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
    int num_args = 0;
    
    while (fgets(buffer, SIZE, stdin) != NULL) {
        // Tokenize the input arguments
        char *token = strtok(buffer, " \n");
        num_args = 0;
        while (token != NULL) {
            input_args = realloc(input_args, (num_args + 1) * sizeof(char*));
            input_args[num_args] = malloc(strlen(token) + 1);
            strcpy(input_args[num_args], token);
            num_args++;
            token = strtok(NULL, " \n");
        }
        
        // Add NULL as the last argument to indicate end of arguments
        input_args = realloc(input_args, (num_args + 1) * sizeof(char*));
        input_args[num_args] = NULL;
        
        // Fork a child process to execute the command
        pid_t pid = fork();
        
        if (pid == 0) {
            // Child process
            execvp(input_args[0], input_args);
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            // Parent process
            wait(NULL);
        } else {
            // Fork failed
            printf("Fork failed.\n");
            exit(EXIT_FAILURE);
        }
        
        // Free the memory allocated for the input arguments
        for (int i = 0; i < num_args; i++) {
            free(input_args[i]);
        }
        free(input_args);
    }
    
    return 0;
}