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
            if (j != 0 ) {
                if (dup2(pipefds[j - 2], 0) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            for (i = 0; i < 2*numPipes; i++){
                close(pipefds[i]);
            }

            if (execvp(*command->args, command->args) < 0) {
                perror(*command->args);
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
    // Example usage of executePipedCommands

    // Creating command 1
    char *args1[] = {"ls", "-l", NULL};
    struct cmd_t command1 = {
        .nargs = 2,
        .maxargs = 3,
        .args = args1,
        .next = NULL
    };
    Cmd cmd1 = &command1;

    // Creating command 2
    char *args2[] = {"grep", "main", NULL};
    struct cmd_t command2 = {
        .nargs = 2,
        .maxargs = 3,
        .args = args2,
        .next = NULL
    };
    Cmd cmd2 = &command2;

    // Creating command 3
    char *args3[] = {"wc", "-l", NULL};
    struct cmd_t command3 = {
        .nargs = 2,
        .maxargs = 3,
        .args = args3,
        .next = NULL
    };
    Cmd cmd3 = &command3;

    // Connecting commands together
    cmd1->next = cmd2;
    cmd2->next = cmd3;

    // Execute the piped commands
    executePipedCommands(cmd1);

    return 0;
}