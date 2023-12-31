List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 26 by call to `malloc`, is not freed after the last access at line 52, column 13.
 Example: 
  50.             // Child process
  51.             // Execute the command
  52.             execvp(input_args[0], input_args);
                  ^
  53. 
  54.             // If execvp fails, print an error message

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 26 by call to `malloc`, is not freed after the last access at line 46, column 13.
 Example: 
  44.         // Fork a child process
  45.         pid_t pid = fork();
  46.         if (pid == -1) {
                  ^
  47.             perror("Error forking process");
  48.             exit(1);


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
        printf("> ");
        // Read input from user
        fgets(buffer, SIZE, stdin);
        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = 0;
        // Split input into arguments
        char *token;
        int i = 0;
        input_args = malloc(MAX_NUM_ARGS * sizeof(char *));
        if (input_args == NULL) {
            perror("Error allocating memory");
            exit(1);
        }
        token = strtok(buffer, " ");
        while (token != NULL) {
            input_args[i] = strdup(token);
            if (input_args[i] == NULL) {
                perror("Error allocating memory");
                exit(1);
            }
            token = strtok(NULL, " ");
            i++;
        }
        input_args[i] = NULL;
        // Fork a child process
        pid_t pid = fork();
        if (pid == -1) {
            perror("Error forking process");
            exit(1);
        } else if (pid == 0) {
            // Child process
            // Execute the command
            execvp(input_args[0], input_args);
            // If execvp fails, print an error message
            perror("Error executing command");
            exit(1);
        } else {
            // Parent process
            // Wait for the child process to finish
            int status;
            waitpid(pid, &status, 0);
            // Free the memory allocated for input arguments
            for (int j = 0; j < i; j++) {
                free(input_args[j]);
            }
            free(input_args);
        }
    }
    return 0;
}