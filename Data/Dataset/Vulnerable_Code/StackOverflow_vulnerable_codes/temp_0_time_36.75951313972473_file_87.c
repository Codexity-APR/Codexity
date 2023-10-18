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

        // Remove newline character from the input
        buffer[strcspn(buffer, "\n")] = 0;

        // Tokenize the input command
        char *token = strtok(buffer, " ");
        int num_args = 0;

        // Allocate memory for input arguments
        input_args = (char **)malloc(MAX_NUM_ARGS * sizeof(char *));

        while (token != NULL) {
            input_args[num_args] = (char *)malloc(strlen(token) + 1);
            strcpy(input_args[num_args], token);
            num_args++;

            token = strtok(NULL, " ");
        }

        // Add NULL as the last argument
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

        // Free memory for input arguments
        for (int i = 0; i < num_args; i++) {
            free(input_args[i]);
        }
        free(input_args);
    }

    return 0;
}