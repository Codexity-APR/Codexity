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
        
        // Remove newline character from buffer
        buffer[strcspn(buffer, "\n")] = '\0';
        
        // Tokenize the input command
        char *token;
        int num_args = 0;
        input_args = malloc(MAX_NUM_ARGS * sizeof(char *));
        if (input_args == NULL) {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }
        
        token = strtok(buffer, " ");
        while (token != NULL) {
            input_args[num_args] = malloc(strlen(token) + 1);
            if (input_args[num_args] == NULL) {
                perror("malloc failed");
                exit(EXIT_FAILURE);
            }
            strcpy(input_args[num_args], token);
            num_args++;
            token = strtok(NULL, " ");
        }
        input_args[num_args] = NULL;
        
        // Execute the command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            if (execvp(input_args[0], input_args) < 0) {
                perror("execvp failed");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            wait(NULL);
        }
        
        // Free memory allocated for input arguments
        for (int i = 0; i < num_args; i++) {
            free(input_args[i]);
        }
        free(input_args);
    }

    return 0;
}