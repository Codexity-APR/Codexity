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

        // Remove newline character from input
        buffer[strcspn(buffer, "\n")] = 0;

        // Tokenize input into separate arguments
        char *token = strtok(buffer, " ");
        int num_args = 0;

        while(token != NULL) {
            input_args = realloc(input_args, sizeof(char*) * (num_args + 1));
            input_args[num_args] = token;
            num_args++;

            token = strtok(NULL, " ");
        }

        // Add NULL terminator to end of argument list
        input_args = realloc(input_args, sizeof(char*) * (num_args + 1));
        input_args[num_args] = NULL;

        // Fork a child process to execute the command
        pid_t pid = fork();

        if(pid == 0) {
            // Child process
            execvp(input_args[0], input_args);
            perror("execvp");
            exit(1);
        } else if(pid > 0) {
            // Parent process
            wait(NULL);
        } else {
            // Error forking
            perror("fork");
            exit(1);
        }

        // Free memory allocated for input arguments
        free(input_args);
        input_args = NULL;
    }

    return 0;
}
