List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 31 by call to `malloc`, is not freed after the last access at line 60, column 13.
 Example: 
  58.                 free(input_args[i]);
  59.             }
  60.             free(input_args);
                  ^
  61.         }
  62.     }

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 24 by call to `malloc`, is not freed after the last access at line 49, column 13.
 Example: 
  47.         } else if (pid == 0) {
  48.             // Child process
  49.             execvp(input_args[0], input_args);
                  ^
  50.             perror("Execvp failed");
  51.             exit(EXIT_FAILURE);

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 24 by call to `malloc`, is not freed after the last access at line 44, column 13.
 Example: 
  42.         // Fork a child process
  43.         pid_t pid = fork();
  44.         if (pid < 0) {
                  ^
  45.             perror("Fork failed");
  46.             exit(EXIT_FAILURE);


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
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
        // Tokenize the input command
        char *token = strtok(buffer, " ");
        int num_args = 0;
        // Allocate memory for input_args
        input_args = (char**) malloc(MAX_NUM_ARGS * sizeof(char*));
        if (input_args == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        while (token != NULL) {
            input_args[num_args] = (char*) malloc((strlen(token) + 1) * sizeof(char));
            if (input_args[num_args] == NULL) {
                perror("Memory allocation failed");
                exit(EXIT_FAILURE);
            }
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
            for (int i = 0; i <= num_args; i++) {
                free(input_args[i]);
            }
            free(input_args);
        }
    }
    return 0;
}