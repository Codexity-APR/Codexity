List of vulnerabilities detected: 
Error: Null Dereference   pointer `input_args` last assigned on line 25 could be null and is dereferenced at line 33, column 9.
 Example: 
  31.             token = strtok(NULL, " ");
  32.         }
  33.         input_args[num_args] = NULL; // Set the last element to NULL
              ^
  34.         
  35.         // Fork a child process

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 25.
 Example: 
  31.             token = strtok(NULL, " ");
  32.         }
  33.         input_args[num_args] = NULL; // Set the last element to NULL
              ^
  34.         
  35.         // Fork a child process

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 25.
 Example: 
  26. 
  27.         while (token != NULL) {
  28.             input_args[num_args] = (char*) malloc((strlen(token) + 1) * sizeof(char));
                  ^
  29.             strcpy(input_args[num_args], token);
  30.             num_args++;

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 25 by call to `malloc`, is not freed after the last access at line 43, column 13.
 Example: 
  41.         } else if (pid == 0) {
  42.             // Child process
  43.             execvp(input_args[0], input_args);
                  ^
  44.             perror("Execvp failed");
  45.             exit(EXIT_FAILURE);

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 25 by call to `malloc`, is not freed after the last access at line 38, column 13.
 Example: 
  36.         pid_t pid = fork();
  37.         
  38.         if (pid < 0) {
                  ^
  39.             perror("Fork failed");
  40.             exit(EXIT_FAILURE);


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