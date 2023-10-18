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
    printf("number of pipes : %d\n", numPipes);

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

            // If not last command
            if (command->next) {
                if (dup2(pipefds[j + 1], 1) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            // If not first command and j != 2*numPipes
            if (j != 0 ) {
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
    struct cmd_t cmd1, cmd2, cmd3;
    char *args1[] = {"ls", "-l", NULL};
    char *args2[] = {"grep", "file.txt", NULL};
    char *args3[] = {"wc", "-l", NULL};

    cmd1.nargs = 2;
    cmd1.maxargs = 2;
    cmd1.args = args1;
    cmd1.next = &cmd2;

    cmd2.nargs = 2;
    cmd2.maxargs = 2;
    cmd2.args = args2;
    cmd2.next = &cmd3;

    cmd3.nargs = 2;
    cmd3.maxargs = 2;
    cmd3.args = args3;
    cmd3.next = NULL;

    executePipedCommands(&cmd1);

    return 0;
}