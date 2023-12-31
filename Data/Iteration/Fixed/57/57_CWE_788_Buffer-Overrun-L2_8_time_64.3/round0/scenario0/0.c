List of vulnerabilities detected: 
Error: Buffer Overrun L2   Offset: [0, 64] Size: 64.
 Example: 
  33.         }
  34.         
  35.         args[i] = NULL; // Make the last element NULL to indicate the end of arguments
              ^
  36.         
  37.         pid_t pid = fork(); // Create a child process

 Error type: CWE-788 at line: 35. Error message: Either the condition 'i<64' is redundant or the array 'args[64]' is accessed at index 64, which is out of bounds.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64
#define PATH_DELIM ":"
int main() {
    char cmd[MAX_CMD_LENGTH]; // buffer to hold user input
    char* args[MAX_ARGS]; // array of strings to hold command arguments
    int status; // exit status of child process
    while (1) {
        printf("[Enter command]> ");
        fgets(cmd, MAX_CMD_LENGTH, stdin); // read user input
        cmd[strcspn(cmd, "\n")] = '\0'; // remove trailing newline
        // check for exit command
        if (strcmp(cmd, "exit") == 0) {
            break;
        }
        // tokenize the command into arguments
        char* token = strtok(cmd, " ");
        int i = 0;
        while (token != NULL && i < MAX_ARGS) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; // Make the last element NULL to indicate the end of arguments
        pid_t pid = fork(); // Create a child process
        if (pid == -1) {
            perror("fork() failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            execvp(args[0], args); // Execute the command
            perror("execvp() failed"); // This line will be reached only if execvp fails
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(&status); // Wait for the child process to complete
        }
    }
    return 0;
}