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
        printf(">> ");
        fgets(buffer, SIZE, stdin);
        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = '\0';
        // Tokenize input string into arguments
        char *token = strtok(buffer, " ");
        int num_args = 0;
        // Allocate memory for input arguments
        input_args = (char **)malloc((MAX_NUM_ARGS + 1) * sizeof(char *)); // Increased size by 1
        if (input_args == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        while (token != NULL) {
            // Allocate memory for each argument
            input_args[num_args] = (char *)malloc(strlen(token) + 1);
            if (input_args[num_args] == NULL) {
                printf("Memory allocation failed\n");
                exit(1);
            }
            // Copy token into argument
            strcpy(input_args[num_args], token);
            num_args++;
            token = strtok(NULL, " ");
        }
        // Add NULL as the last argument
        input_args[num_args] = NULL;
        // Fork a child process
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            execvp(input_args[0], input_args);
            printf("Command not found\n");
            exit(1);
        } else if (pid < 0) {
            // Error occurred while forking
            printf("Error occurred while forking\n");
        } else {
            // Parent process
            wait(NULL);
        }
        // Free allocated memory for input arguments
        for (int i = 0; i <= num_args; i++) {
            free(input_args[i]);
        }
        free(input_args);
    }
    return 0;
}