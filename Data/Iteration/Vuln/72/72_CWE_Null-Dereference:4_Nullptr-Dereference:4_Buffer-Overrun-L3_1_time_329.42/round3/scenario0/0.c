List of vulnerabilities detected: 
Error: Buffer Overrun L3   Offset: [1, +oo] Size: [0, +oo].
 Example: 
  44.             //if not last command
  45.             if (command->next) {
  46.                 if (dup2(pipefds[j + 1], 1) < 0) {
                               ^
  47.                     perror("dup2");
  48.                     exit(EXIT_FAILURE);


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
struct cmd_t {
    int nargs, maxargs;
    char **args;
    struct cmd_t *next;
};
typedef struct cmd_t *Cmd;
void executePipedCommands(Cmd command) {
    int numPipes = 0;
    Cmd temp = command;
    int status;
    int i = 0;
    pid_t pid;
    while (command != NULL) {
        numPipes++;
        command = command->next;
    }
    printf("number of pipes: %d\n", numPipes);
    int pipefds[2*numPipes];
    for (i = 0; i < (numPipes); i++) {
        if (pipe(pipefds + i*2) < 0) {
            perror("couldn't pipe");
            exit(EXIT_FAILURE);
        }
    }
    int j = 0;
    command = temp;
    while (command) {
        pid = fork();
        if (pid == 0) {
            //if not last command
            if (command->next) {
                if (dup2(pipefds[j + 1], 1) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            //if not first command && j != 2*numPipes
            if (j != 0 && j-2 >= 0) {
                if (dup2(pipefds[j-2], 0) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            for (i = 0; i < 2*numPipes; i++){
                close(pipefds[i]);
            }
            if (execvp(command->args[0], command->args) < 0) {
                perror(command->args[0]);
                exit(EXIT_FAILURE);
            }
        } else if (pid < 0) {
            perror("error");
            exit(EXIT_FAILURE);
        }
        command = command->next;
        j += 2;
    }
    for (i = 0; i < 2 * numPipes; i++){
        close(pipefds[i]);
    }
    for (i = 0; i < numPipes + 1; i++){
        wait(&status);
    }
}
int main() {
    // Example usage
    Cmd cmd1 = malloc(sizeof(struct cmd_t));
    if (cmd1 == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    cmd1->nargs = 3;
    cmd1->maxargs = 3;
    cmd1->args = malloc(cmd1->maxargs * sizeof(char *));
    if (cmd1->args == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    cmd1->args[0] = "ls";
    cmd1->args[1] = "-l";
    cmd1->args[2] = NULL;
    Cmd cmd2 = malloc(sizeof(struct cmd_t));
    if (cmd2 == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    cmd2->nargs = 3;
    cmd2->maxargs = 3;
    cmd2->args = malloc(cmd2->maxargs * sizeof(char *));
    if (cmd2->args == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    cmd2->args[0] = "grep";
    cmd2->args[1] = "hello";
    cmd2->args[2] = NULL;
    cmd1->next = cmd2;
    cmd2->next = NULL;
    executePipedCommands(cmd1);
    return 0;
}