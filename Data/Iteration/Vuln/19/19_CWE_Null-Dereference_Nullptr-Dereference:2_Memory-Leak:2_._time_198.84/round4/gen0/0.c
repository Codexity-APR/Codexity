#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_NUM_ARGS 256
#define SIZE 256

int main() {
    char buffer[SIZE] = "";
    char **input_args = NULL;
    while (1) {
        printf("> ");
        // Read input from user
        fgets(buffer, SIZE, stdin);
        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = 0;
        // Split input into arguments
        char *token;
        int i = 0;
        input_args = malloc(MAX_NUM_ARGS * sizeof(char *));
        if (input_args == NULL) {
            perror("Error allocating memory");
            exit(1);
        }
        token = strtok(buffer, " ");
        while (token != NULL) {
            input_args[i] = strdup(token);
            if (input_args[i] == NULL) {
                perror("Error allocating memory");
                exit(1);
            }
            token = strtok(NULL, " ");
            i++;
        }
        input_args[i] = NULL;
        // Fork a child process
        pid_t pid = fork();
        if (pid == -1) {
            perror("Error forking process");
            exit(1);
        } else if (pid == 0) {
            // Child process
            // Execute the command
            execvp(input_args[0], input_args);
            // If execvp fails, print an error message
            perror("Error executing command");
            // Free the memory allocated for input arguments
            for (int j = 0; j < i; j++) {
                free(input_args[j]);
            }
            free(input_args);
            exit(1);
        } else {
            // Parent process
            // Wait for the child process to finish
            int status;
            waitpid(pid, &status, 0);
            // Free the memory allocated for input arguments
            for (int j = 0; j < i; j++) {
                free(input_args[j]);
            }
            free(input_args);
        }
    }
    return 0;
}