List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 28 by call to `malloc`, is not freed after the last access at line 39, column 9.
 Example: 
  37. 
  38.         // Append NULL to the end of the argument list for execvp
  39.         input_args = realloc(input_args, sizeof(char *) * (num_args + 1));
              ^
  40.         if (input_args == NULL) {
  41.             perror("Memory allocation failed");

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 28 by call to `malloc`, is not freed after the last access at line 23, column 13.
 Example: 
  21.         char *token = strtok(buffer, " ");
  22.         while (token != NULL) {
  23.             input_args = realloc(input_args, sizeof(char *) * (num_args + 1));
                  ^
  24.             if (input_args == NULL) {
  25.                 perror("Memory allocation failed");


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
        printf(">> ");
        fgets(buffer, SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // remove trailing newline character
        // Tokenize the input string
        int num_args = 0;
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            input_args = realloc(input_args, sizeof(char *) * (num_args + 1));
            if (input_args == NULL) {
                perror("Memory allocation failed");
                exit(EXIT_FAILURE);
            }
            input_args[num_args] = malloc(sizeof(char) * (strlen(token) + 1));
            if (input_args[num_args] == NULL) {
                perror("Memory allocation failed");
                exit(EXIT_FAILURE);
            }
            strcpy(input_args[num_args], token);
            num_args++;
            token = strtok(NULL, " ");
        }
        // Append NULL to the end of the argument list for execvp
        input_args = realloc(input_args, sizeof(char *) * (num_args + 1));
        if (input_args == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
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