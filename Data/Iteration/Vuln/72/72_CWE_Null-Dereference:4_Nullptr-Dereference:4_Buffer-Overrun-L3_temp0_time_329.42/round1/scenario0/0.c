List of vulnerabilities detected: 
Error: Null Dereference   pointer `command2` last assigned on line 97 could be null and is dereferenced at line 98, column 5.
 Example: 
   96. 
   97.     Cmd command2 = malloc(sizeof(struct cmd_t));
   98.     command2->nargs = 3;
           ^
   99.     command2->maxargs = 3;
  100.     command2->args = malloc(sizeof(char*) * 4);

Error: Null Dereference   pointer `command2->args` last assigned on line 100 could be null and is dereferenced at line 101, column 5.
 Example: 
   99.     command2->maxargs = 3;
  100.     command2->args = malloc(sizeof(char*) * 4);
  101.     command2->args[0] = "grep";
           ^
  102.     command2->args[1] = "file";
  103.     command2->args[2] = NULL;

Error: Null Dereference   pointer `command1` last assigned on line 88 could be null and is dereferenced at line 89, column 5.
 Example: 
  87.     // Example usage
  88.     Cmd command1 = malloc(sizeof(struct cmd_t));
  89.     command1->nargs = 3;
          ^
  90.     command1->maxargs = 3;
  91.     command1->args = malloc(sizeof(char*) * 4);

Error: Null Dereference   pointer `command1->args` last assigned on line 91 could be null and is dereferenced at line 92, column 5.
 Example: 
  90.     command1->maxargs = 3;
  91.     command1->args = malloc(sizeof(char*) * 4);
  92.     command1->args[0] = "ls";
          ^
  93.     command1->args[1] = "-l";
  94.     command1->args[2] = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 97.
 Example: 
   96. 
   97.     Cmd command2 = malloc(sizeof(struct cmd_t));
   98.     command2->nargs = 3;
           ^
   99.     command2->maxargs = 3;
  100.     command2->args = malloc(sizeof(char*) * 4);

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 91.
 Example: 
  90.     command1->maxargs = 3;
  91.     command1->args = malloc(sizeof(char*) * 4);
  92.     command1->args[0] = "ls";
          ^
  93.     command1->args[1] = "-l";
  94.     command1->args[2] = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 88.
 Example: 
  87.     // Example usage
  88.     Cmd command1 = malloc(sizeof(struct cmd_t));
  89.     command1->nargs = 3;
          ^
  90.     command1->maxargs = 3;
  91.     command1->args = malloc(sizeof(char*) * 4);

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 100.
 Example: 
   99.     command2->maxargs = 3;
  100.     command2->args = malloc(sizeof(char*) * 4);
  101.     command2->args[0] = "grep";
           ^
  102.     command2->args[1] = "file";
  103.     command2->args[2] = NULL;

Error: Buffer Overrun L3   Offset: [-1, +oo] Size: [0, +oo].
 Example: 
  52.             // If not the first command && j != 2 * numPipes
  53.             if (j != 0) {
  54.                 if (dup2(pipefds[j - 2], 0) < 0) {
                               ^
  55.                     perror("dup2");
  56.                     exit(EXIT_FAILURE);


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
    int pipefds[2 * numPipes];
    for (i = 0; i < (numPipes); i++) {
        if (pipe(pipefds + i * 2) < 0) {
            perror("couldn't pipe");
            exit(EXIT_FAILURE);
        }
    }
    int j = 0;
    command = temp;
    while (command) {
        pid = fork();
        if (pid == 0) {
            // If not the last command
            if (command->next) {
                if (dup2(pipefds[j + 1], 1) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            // If not the first command && j != 2 * numPipes
            if (j != 0) {
                if (dup2(pipefds[j - 2], 0) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            for (i = 0; i < 2 * numPipes; i++) {
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
    for (i = 0; i < 2 * numPipes; i++) {
        close(pipefds[i]);
    }
    for (i = 0; i < numPipes + 1; i++) {
        wait(&status);
    }
}
int main() {
    // Example usage
    Cmd command1 = malloc(sizeof(struct cmd_t));
    command1->nargs = 3;
    command1->maxargs = 3;
    command1->args = malloc(sizeof(char*) * 4);
    command1->args[0] = "ls";
    command1->args[1] = "-l";
    command1->args[2] = NULL;
    command1->next = NULL;
    Cmd command2 = malloc(sizeof(struct cmd_t));
    command2->nargs = 3;
    command2->maxargs = 3;
    command2->args = malloc(sizeof(char*) * 4);
    command2->args[0] = "grep";
    command2->args[1] = "file";
    command2->args[2] = NULL;
    command2->next = NULL;
    command1->next = command2;
    executePipedCommands(command1);
    free(command1->args);
    free(command1);
    free(command2->args);
    free(command2);
    return 0;
}