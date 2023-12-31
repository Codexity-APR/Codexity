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
        printf("> ");

        fgets(buffer, SIZE, stdin);

        // Remove trailing newline character
        if(buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }

        // Tokenize the input string
        char *token = strtok(buffer, " ");

        int arg_count = 0;
        while(token != NULL) {
            input_args = realloc(input_args, (arg_count + 1) * sizeof(char *));
            input_args[arg_count] = strdup(token);
            arg_count++;

            token = strtok(NULL, " ");
        }

        // Set the last element of input_args to NULL
        input_args = realloc(input_args, (arg_count + 1) * sizeof(char *));
        input_args[arg_count] = NULL;

        // Fork a child process
        pid_t pid = fork();

        if(pid == -1) {
            perror("Fork failed");
            exit(1);
        }
        else if(pid == 0) {
            // Child process

            // Execute the command
            execvp(input_args[0], input_args);

            // If execvp fails, print error message and exit child process
            perror("Execvp failed");
            exit(1);
        }
        else {
            // Parent process

            // Wait for the child process to finish
            wait(NULL);
        }

        // Free the memory allocated for input_args
        for(int i = 0; i < arg_count; i++) {
            free(input_args[i]);
        }
        free(input_args);
    }

    return 0;
}