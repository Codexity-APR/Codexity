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
        printf("> ");

        fgets(buffer, SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        // Tokenize the input arguments
        char *token = strtok(buffer, " ");
        int num_args = 0;

        input_args = malloc(MAX_NUM_ARGS * sizeof(char*));
        while (token != NULL) {
            input_args[num_args] = token;
            num_args++;
            token = strtok(NULL, " ");
        }

        // Add NULL as the last argument to comply with execvp() requirements
        input_args[num_args] = NULL;

        // Fork a child process
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            // Child process

            // Execute the command
            if (execvp(input_args[0], input_args) == -1) {
                perror("Exec failed");
                exit(1);
            }

            exit(0);
        } else {
            // Parent process

            // Wait for the child process to complete
            int status;
            waitpid(pid, &status, 0);
        }

        // Free the allocated memory for input arguments
        free(input_args);
    }

    return 0;
}