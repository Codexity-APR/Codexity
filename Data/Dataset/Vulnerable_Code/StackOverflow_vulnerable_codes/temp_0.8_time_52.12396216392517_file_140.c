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

    while(1) {
        // Prompt user for input
        printf("Enter a command: ");

        // Read input from user
        fgets(buffer, SIZE, stdin);

        // Trim the newline character from the input
        buffer[strcspn(buffer, "\n")] = '\0';

        // Tokenize the input into separate arguments
        char *token = strtok(buffer, " ");
        int num_args = 0;

        while (token != NULL) {
            // Reallocate memory to store the arguments
            input_args = realloc(input_args, (num_args + 1) * sizeof(char *));
            input_args[num_args] = malloc(strlen(token) + 1);
            strcpy(input_args[num_args], token);
            num_args++;

            token = strtok(NULL, " ");
        }

        // Terminate the argument list with a NULL pointer
        input_args = realloc(input_args, (num_args + 1) * sizeof(char *));
        input_args[num_args] = NULL;

        // Fork a child process
        pid_t pid = fork();

        if (pid == 0) {
            // Child process

            // Execute the command
            execvp(input_args[0], input_args);

            // If execvp returns, it means the command execution failed
            printf("Command not found: %s\n", input_args[0]);
            exit(1);
        } else if (pid > 0) {
            // Parent process

            // Wait for the child process to complete
            wait(NULL);
        } else {
            // Forking failed
            printf("Forking a child process failed.\n");
            exit(1);
        }

        // Free the allocated memory for arguments
        for (int i = 0; i < num_args; i++) {
            free(input_args[i]);
        }
        free(input_args);
    }

    return 0;
}