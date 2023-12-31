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
        printf("Enter a command: ");
        fgets(buffer, SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline

        // Tokenize the input command
        char *token = strtok(buffer, " ");
        int num_args = 0;

        // Allocate memory for input_args
        input_args = (char**) malloc(MAX_NUM_ARGS * sizeof(char*));

        while (token != NULL) {
            input_args[num_args] = (char*) malloc((strlen(token) + 1) * sizeof(char));
            strcpy(input_args[num_args], token);
            num_args++;
            token = strtok(NULL, " ");
        }
        input_args[num_args] = NULL; // Set the last element to NULL
        
        // Fork a child process
        pid_t pid = fork();
        
        if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execvp(input_args[0], input_args);
            perror("Execvp failed");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(NULL);
            
            // Free memory for input_args
            for (int i = 0; i < num_args; i++) {
                free(input_args[i]);
            }
            free(input_args);
        }
    }
    
    return 0;
}