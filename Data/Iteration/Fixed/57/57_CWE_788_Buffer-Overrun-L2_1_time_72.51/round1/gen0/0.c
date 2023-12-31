#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64
#define PATH_DELIM ":"

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

        // tokenize the command into arguments
        char* token = strtok(cmd, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; // set the last element of args to NULL as required by execvp()

        pid_t pid = fork(); // create a child process
        if (pid == 0) {
            // child process
            execvp(args[0], args); // execute the command
            perror("Command execution failed");
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // error creating child process
            perror("Failed to create child process");
            exit(EXIT_FAILURE);
        } else {
            // parent process
            waitpid(pid, &status, 0); // wait for the child process to finish
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                printf("Child process exited with status %d\n", exit_status);
            }
        }
    }

    return 0;
}