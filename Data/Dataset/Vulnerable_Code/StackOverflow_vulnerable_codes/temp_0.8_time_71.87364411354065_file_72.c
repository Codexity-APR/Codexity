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

            // if not last command
            if (command->next) {
                if (dup2(pipefds[j + 1], 1) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            // if not first command && j != 2*numPipes
            if (j != 0 ) {
                if (dup2(pipefds[j-2], 0) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            for (i = 0; i < 2*numPipes; i++) {
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

    Cmd command = malloc(sizeof(struct cmd_t));
    command->nargs = 3;
    command->maxargs = 3;
    command->args = malloc(sizeof(char*) * 3);
    command->args[0] = "ls";
    command->args[1] = "-l";
    command->args[2] = NULL;
    command->next = malloc(sizeof(struct cmd_t));
    command->next->nargs = 2;
    command->next->maxargs = 2;
    command->next->args = malloc(sizeof(char*) * 2);
    command->next->args[0] = "grep";
    command->next->args[1] = "file";
    command->next->next = NULL;

    executePipedCommands(command);

    return 0;
}