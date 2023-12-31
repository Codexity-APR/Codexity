#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

int main() {
    char cmd[MAX_CMD_LENGTH]; // buffer to hold user input
    char* args[MAX_ARGS + 1]; // array of strings to hold command arguments (+1 for NULL terminator)
    int status; // exit status of child process

    while (1) {
        printf("[Enter command]> ");
        fgets(cmd, MAX_CMD_LENGTH, stdin); // read user input
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

            args[i] = NULL; // set the last argument to NULL

            // execute the command
            execvp(args[0], args);

            // if execvp fails, print an error message
            fprintf(stderr, "Error: Command not found.\n");
            exit(1);
        } else if (pid > 0) { // parent process
            // wait for the child process to terminate
            waitpid(pid, &status, 0);
        } else { // fork failed
            fprintf(stderr, "Error: Fork failed.\n");
            exit(1);
        }
    }

    return 0;
}