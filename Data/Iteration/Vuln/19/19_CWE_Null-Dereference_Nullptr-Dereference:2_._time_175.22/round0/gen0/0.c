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
        fgets(buffer, sizeof(buffer), stdin);

        // Removing newline character from the end of the input
        buffer[strcspn(buffer, "\n")] = 0;

        // Tokenizing the input command
        char *token = strtok(buffer, " ");
        int num_args = 0;

        // Dynamically allocating memory for input arguments
        input_args = (char**)malloc(MAX_NUM_ARGS * sizeof(char*));

        while (token != NULL) {
            input_args[num_args] = (char*)malloc(strlen(token) + 1);
            strcpy(input_args[num_args], token);
            token = strtok(NULL, " ");
            num_args++;
        }

        // Adding NULL as the last element to indicate the end of arguments
        input_args[num_args] = NULL;

        // Forking a child process to execute the command
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            execvp(input_args[0], input_args);
            exit(0);
        } else {
            // Parent process
            wait(NULL);
        }

        // Freeing the dynamically allocated memory for input arguments
        for (int i = 0; i < num_args; i++) {
            free(input_args[i]);
        }
        free(input_args);
    }

    return 0;
}