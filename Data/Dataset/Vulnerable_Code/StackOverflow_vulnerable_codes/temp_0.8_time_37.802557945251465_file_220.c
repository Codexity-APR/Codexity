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
        buffer[strcspn(buffer, "\n")] = 0; // remove trailing newline character

        // Tokenize the input command
        char *token = strtok(buffer, " ");
        int arg_count = 0;

        while (token != NULL) {
            input_args = realloc(input_args, (arg_count + 1) * sizeof(char *));
            input_args[arg_count] = malloc(strlen(token) + 1);
            strcpy(input_args[arg_count], token);
            arg_count++;
            token = strtok(NULL, " ");
        }

        // Add NULL as the last element of the array
        input_args = realloc(input_args, (arg_count + 1) * sizeof(char *));
        input_args[arg_count] = NULL;

        // Execute the command
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
            waitpid(pid, NULL, 0);
        }

        // Free the allocated memory
        for (int i = 0; i <= arg_count; i++) {
            free(input_args[i]);
        }
        free(input_args);
        input_args = NULL;
    }

    return 0;
}