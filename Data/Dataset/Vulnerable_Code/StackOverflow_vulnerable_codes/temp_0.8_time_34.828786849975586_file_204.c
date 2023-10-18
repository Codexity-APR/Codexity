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

        // Remove newline character from the input
        buffer[strcspn(buffer, "\n")] = 0;

        // Split the input into arguments
        char *token = strtok(buffer, " ");
        int arg_count = 0;
        
        while (token != NULL) {
            input_args = realloc(input_args, (arg_count + 1) * sizeof(char*));
            input_args[arg_count] = malloc(strlen(token) + 1);
            strcpy(input_args[arg_count], token);
            arg_count++;
            token = strtok(NULL, " ");
        }
        
        input_args = realloc(input_args, (arg_count + 1) * sizeof(char*));
        input_args[arg_count] = NULL;

        // Fork a child process to execute the command
        pid_t pid = fork();
        
        if (pid == -1) {
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {
            // Child process
            execvp(input_args[0], input_args);
            perror("execvp failed");
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