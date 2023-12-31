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
        // Print the prompt
        printf(">> ");

        // Read the input from the user
        fgets(buffer, SIZE, stdin);

        // Remove the trailing newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Tokenize the input arguments
        char *token = strtok(buffer, " ");
        int num_args = 0;

        while (token != NULL) {
            input_args = realloc(input_args, (num_args + 1) * sizeof(char *));
            if (input_args == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
            input_args[num_args] = token;
            num_args++;
            token = strtok(NULL, " ");
        }

        // Add a NULL at the end of the argument list for execvp
        input_args = realloc(input_args, (num_args + 1) * sizeof(char *));
        if (input_args == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        input_args[num_args] = NULL;

        // Fork a new process to execute the command
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execvp(input_args[0], input_args);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(NULL);
        }

        // Free the memory allocated for input_args
        free(input_args);
        input_args = NULL;
    }

    return 0;
}