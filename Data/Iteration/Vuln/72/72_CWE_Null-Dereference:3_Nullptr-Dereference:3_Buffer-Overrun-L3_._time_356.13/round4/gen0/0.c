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
            // If not the last command
            if (command->next) {
                if (dup2(pipefds[j + 1], STDOUT_FILENO) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            // If not the first command and j != 2*numPipes
            if (j != 0 && (j - 2) >= 0) {
                if (dup2(pipefds[j-2], STDIN_FILENO) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }

            // Close all pipe file descriptors
            for (i = 0; i < 2*numPipes; i++) {
                close(pipefds[i]);
            }

            // Execute the command
            if (execvp(command->args[0], command->args) < 0) {
                perror(command->args[0]);
                exit(EXIT_FAILURE);
            }
        } else if (pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }

        command = command->next;
        j += 2;
    }

    // Close all pipe file descriptors
    for (i = 0; i < 2*numPipes; i++) {
        close(pipefds[i]);
    }

    // Wait for all child processes to finish
    for (i = 0; i < numPipes + 1; i++) {
        wait(&status);
    }
}

int main() {
    // Create sample commands
    char *cmd1[] = {"ls", "-l", NULL};
    char *cmd2[] = {"grep", "file", NULL};
    char *cmd3[] = {"wc", "-l", NULL};

    // Create command nodes
    Cmd command1 = (Cmd)malloc(sizeof(struct cmd_t));
    if (command1 == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    command1->nargs = 2;
    command1->maxargs = 2;
    command1->args = cmd1;
    command1->next = NULL;

    Cmd command2 = (Cmd)malloc(sizeof(struct cmd_t));
    if (command2 == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    command2->nargs = 2;
    command2->maxargs = 2;
    command2->args = cmd2;
    command2->next = NULL;

    Cmd command3 = (Cmd)malloc(sizeof(struct cmd_t));
    if (command3 == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    command3->nargs = 2;
    command3->maxargs = 2;
    command3->args = cmd3;
    command3->next = NULL;

    // Build the command pipeline
    command1->next = command2;
    command2->next = command3;

    // Execute the piped commands
    executePipedCommands(command1);

    return 0;
}