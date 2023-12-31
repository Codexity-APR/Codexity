#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

int main() {
    char cmd[MAX_CMD_LENGTH]; // buffer to hold user input
    char* args[MAX_ARGS]; // array of strings to hold command arguments
    int status; // exit status of child process

    while (1) {
        printf("[Enter command]> ");
        if (fgets(cmd, MAX_CMD_LENGTH, stdin) == NULL) { // error reading input
            perror("fgets");
            break;
        }
        cmd[strcspn(cmd, "\n")] = '\0'; // remove trailing newline

        // check for exit command
        if (strcmp(cmd, "exit") == 0) {
            break;
        }

        pid_t pid = fork(); // create a new process

        if (pid == 0) { // child process
            // tokenize the command into arguments
            char* token = strtok(cmd, " ");
            int i = 0;
            while (token != NULL && i < MAX_ARGS) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL; // set the last argument to NULL for execvp

            // execute the command
            execvp(args[0], args);
            perror("execvp"); // exec failed
            exit(EXIT_FAILURE);
        } else if (pid < 0) { // fork failed
            perror("fork");
            exit(EXIT_FAILURE);
        } else { // parent process
            waitpid(pid, &status, 0); // wait for child to exit
            if (WIFSIGNALED(status)) { // child was terminated by a signal
                fprintf(stderr, "Child process terminated with signal %d\n", WTERMSIG(status));
            }
        }
    }

    return 0;
}