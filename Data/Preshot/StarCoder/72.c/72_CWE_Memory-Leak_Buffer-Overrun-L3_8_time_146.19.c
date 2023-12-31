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

void freeCommand(Cmd cmd) {
    if (cmd->args != NULL) {
        free(cmd->args);
        cmd->args = NULL;
    }
    free(cmd);
}

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
            //if not last command
            if (command->next) {
                if (dup2(pipefds[j + 1], 1) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            //if not first command && j!= 2*numPipes
            if (j != 0) {
                if (dup2(pipefds[j - 2], 0) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            //if first command
            if (j == 0) {
                if (dup2(pipefds[j + 1], 1) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            //if last command
            if (command->next == NULL) {
                if (dup2(pipefds[j], 0) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            //execute command
            if (execvp(command->args[0], command->args) < 0) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else {
            j += 2;
        }
        command = command->next;
    }

    for (i = 0; i < numPipes; i++) {
        close(pipefds[i*2]);
        close(pipefds[i*2 + 1]);
    }

    for (i = 0; i < numPipes; i++) {
        wait(&status);
    }

    while (temp != NULL) {
        command = temp->next;
        freeCommand(temp);
        temp = command;
    }
}

int main(int argc, char *argv[]) {

    Cmd command = NULL;
    Cmd temp = NULL;
    int i = 0;

    while (i < argc) {
        if (strcmp(argv[i], "|") == 0) {
            if (command == NULL) {
                printf("Error: No command before |\n");
                exit(EXIT_FAILURE);
            } else {
                temp = command;
                command = (Cmd) malloc(sizeof(struct cmd_t));
                if (command == NULL) {
                    perror("malloc");
                    exit(EXIT_FAILURE);
                }
                command->nargs = 0;
                command->maxargs = 10;
                command->args = (char **) malloc(command->maxargs * sizeof(char *));
                if (command->args == NULL) {
                    perror("malloc");
                    freeCommand(command);
                    exit(EXIT_FAILURE);
                }
                command->next = NULL;
                command->args[command->nargs++] = argv[i];
                command->args[command->nargs++] = temp->args[0];
                command->args[command->nargs++] = NULL;
                temp->next = command;
            }
        } else {
            if (command == NULL) {
                command = (Cmd) malloc(sizeof(struct cmd_t));
                if (command == NULL) {
                    perror("malloc");
                    exit(EXIT_FAILURE);
                }
                command->nargs = 0;
                command->maxargs = 10;
                command->args = (char **) malloc(command->maxargs * sizeof(char *));
                if (command->args == NULL) {
                    perror("malloc");
                    freeCommand(command);
                    exit(EXIT_FAILURE);
                }
                command->next = NULL;
            }
            if (command->nargs == command->maxargs) {
                command->maxargs += 10;
                command->args = (char **) realloc(command->args, command->maxargs * sizeof(char *));
                if (command->args == NULL) {
                    perror("realloc");
                    freeCommand(command);
                    exit(EXIT_FAILURE);
                }
            }
            command->args[command->nargs++] = argv[i];
        }
        i++;
    }

    executePipedCommands(command);

    return 0;
}