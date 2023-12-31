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
        printf(">> ");
        fgets(buffer, SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // remove trailing newline character

        // Tokenize the input string
        int num_args = 0;
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            input_args = realloc(input_args, sizeof(char *) * (num_args + 1));
            input_args[num_args] = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(input_args[num_args], token);
            num_args++;
            token = strtok(NULL, " ");
        }

        // Append NULL to the end of the argument list for execvp
        input_args = realloc(input_args, sizeof(char *) * (num_args + 1));
        input_args[num_args] = NULL;

        // Fork a new process
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            execvp(input_args[0], input_args);
            perror("Execvp failed");
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            // Parent process
            wait(NULL);
        } else {
            // Fork failed
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        // Free memory allocated for input arguments
        for (int i = 0; i < num_args; i++) {
            free(input_args[i]);
        }
        free(input_args);
    }

    return 0;
}