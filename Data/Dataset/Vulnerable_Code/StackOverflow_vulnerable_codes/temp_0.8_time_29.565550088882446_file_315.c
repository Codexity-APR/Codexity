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
        buffer[strcspn(buffer, "\n")] = 0;

        // Tokenize the input arguments
        char *token;
        int arg_count = 0;
        input_args = (char **) malloc(MAX_NUM_ARGS * sizeof(char *));
        token = strtok(buffer, " ");
        while (token != NULL) {
            input_args[arg_count] = (char *) malloc(SIZE * sizeof(char));
            strcpy(input_args[arg_count], token);
            arg_count++;
            token = strtok(NULL, " ");
        }
        input_args[arg_count] = NULL;

        // Execute the command
        pid_t pid = fork();
        if (pid == 0) {
            execvp(input_args[0], input_args);
            exit(0);
        } else {
            wait(NULL);
        }

        // Free the allocated memory
        for (int i = 0; i < arg_count; i++) {
            free(input_args[i]);
        }
        free(input_args);
    }

    return 0;
}