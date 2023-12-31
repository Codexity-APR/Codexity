#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

int main() {
    char cmd[MAX_CMD_LENGTH];
    char* args[MAX_ARGS];
    int status;

    while (1) {
        printf("[Enter command]> ");
        fgets(cmd, MAX_CMD_LENGTH, stdin);
        cmd[strcspn(cmd, "\n")] = '\0';

        if (strcmp(cmd, "exit") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid == 0) {
            char* token = strtok(cmd, " ");
            int i = 0;
            while (token != NULL && i < MAX_ARGS) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL; // Set the last element of args array to NULL
            execvp(args[0], args);
            perror("Error: execvp failed"); // Print error message if execvp fails
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            waitpid(pid, &status, 0);
        } else {
            perror("Error: fork failed"); // Print error message if fork fails
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}