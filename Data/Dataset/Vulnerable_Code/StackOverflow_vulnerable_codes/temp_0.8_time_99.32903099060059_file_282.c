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

            //if not last command
            if (command->next) {
                if (dup2(pipefds[j + 1], 1) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            //if not first command && j!= 2*numPipes
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

    for (i = 0; i < numPipes + 1; i++)
        wait(&status);
}

int main() {
    // Create commands
    Cmd command1 = malloc(sizeof(struct cmd_t));
    command1->nargs = 3;
    command1->maxargs = 3;
    command1->args = malloc(sizeof(char*) * command1->maxargs);
    command1->args[0] = "ls";
    command1->args[1] = "-l";
    command1->args[2] = NULL;

    Cmd command2 = malloc(sizeof(struct cmd_t));
    command2->nargs = 3;
    command2->maxargs = 3;
    command2->args = malloc(sizeof(char*) * command2->maxargs);
    command2->args[0] = "grep";
    command2->args[1] = "keyword";
    command2->args[2] = NULL;

    Cmd command3 = malloc(sizeof(struct cmd_t));
    command3->nargs = 2;
    command3->maxargs = 2;
    command3->args = malloc(sizeof(char*) * command3->maxargs);
    command3->args[0] = "wc";
    command3->args[1] = "-l";
    command3->args[2] = NULL;

    // Link commands together
    command1->next = command2;
    command2->next = command3;
    command3->next = NULL;

    // Execute piped commands
    executePipedCommands(command1);

    // Free memory
    free(command1->args);
    free(command1);
    free(command2->args);
    free(command2);
    free(command3->args);
    free(command3);

    return 0;
}