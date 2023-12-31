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
        args[i] = NULL; // set the last element of args to NULL

        // fork a child process
        pid_t pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            exit(1);
        } else if (pid == 0) {
            // child process
            execvp(args[0], args); // execute the command
            fprintf(stderr, "Command execution failed\n");
            exit(1);
        } else {
            // parent process
            wait(&status); // wait for the child process to terminate
        }
    }

    return 0;
}