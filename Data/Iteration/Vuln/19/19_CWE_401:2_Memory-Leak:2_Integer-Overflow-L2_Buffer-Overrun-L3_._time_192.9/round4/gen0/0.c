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
        printf("Enter a command: ");
        fgets(buffer, SIZE, stdin);

        // Remove trailing newline character from buffer
        size_t buffer_length = strlen(buffer);
        if (buffer_length > 0 && buffer[buffer_length - 1] == '\n') {
            buffer[buffer_length - 1] = '\0';
        }

        // Tokenize the input command
        char *token = strtok(buffer, " ");
        int num_args = 0;

        while (token != NULL) {
            input_args = realloc(input_args, (num_args + 1) * sizeof(char *));
            if (input_args == NULL) {
                perror("Memory allocation failed");
                exit(1);
            }

            input_args[num_args] = malloc(strlen(token) + 1);
            if (input_args[num_args] == NULL) {
                perror("Memory allocation failed");
                exit(1);
            }

            strcpy(input_args[num_args], token);
            token = strtok(NULL, " ");
            num_args++;
        }

        // Append NULL at the end of input_args to indicate end of arguments
        input_args = realloc(input_args, (num_args + 1) * sizeof(char *));
        if (input_args == NULL) {
            perror("Memory allocation failed");
            exit(1);
        }

        input_args[num_args] = NULL;

        // Fork a child process
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            // Child process
            execvp(input_args[0], input_args);
            perror("Execvp failed");
            exit(1);
        } else {
            // Parent process
            wait(NULL);
        }

        // Free allocated memory for input_args
        for (int i = 0; i < num_args; i++) {
            free(input_args[i]);
        }
        free(input_args);
        input_args = NULL;
    }

    return 0;
}