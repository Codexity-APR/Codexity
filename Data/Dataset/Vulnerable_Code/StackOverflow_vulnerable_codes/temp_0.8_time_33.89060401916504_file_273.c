#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_NUM_ARGS 256
#define SIZE 256

int main() {

    char buffer[SIZE]= "";
    char **input_args = NULL;

    while (1) {
        printf("Enter a command: ");
        fgets(buffer, SIZE, stdin);

        // Remove the trailing newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Tokenize the input command
        char *token = strtok(buffer, " ");
        int arg_count = 0;

        // Allocate memory for arguments
        input_args = malloc(MAX_NUM_ARGS * sizeof(char *));

        // Parse the command into arguments
        while (token != NULL) {
            input_args[arg_count] = strdup(token);
            arg_count++;
            token = strtok(NULL, " ");
        }

        // Set the last argument to NULL
        input_args[arg_count] = NULL;

        // Fork a child process
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }

        if (pid == 0) {
            // Child process
            execvp(input_args[0], input_args);
            perror("Execvp failed");
            exit(1);
        } else {
            // Parent process
            wait(NULL);
        }

        // Free allocated memory
        for (int i = 0; i < arg_count; i++) {
            free(input_args[i]);
        }
        free(input_args);
    }

    return 0;
}