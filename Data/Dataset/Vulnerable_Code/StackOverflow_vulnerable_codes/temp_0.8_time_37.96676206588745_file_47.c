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

        // Remove trailing newline character
        if(buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }

        // Split the input into separate arguments
        int arg_count = 0;
        char *arg = strtok(buffer, " ");
        while(arg != NULL) {
            input_args = realloc(input_args, (arg_count+1) * sizeof(char*));
            input_args[arg_count] = malloc(strlen(arg) + 1);
            strcpy(input_args[arg_count], arg);
            arg_count++;
            arg = strtok(NULL, " ");
        }
        input_args = realloc(input_args, (arg_count+1) * sizeof(char*));
        input_args[arg_count] = NULL;

        // Fork a child process
        pid_t pid = fork();

        if(pid == -1) {
            // Error occurred while forking
            perror("fork");
            exit(EXIT_FAILURE);
        } else if(pid == 0) {
            // Child process
            execvp(input_args[0], input_args);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            waitpid(pid, NULL, 0);
        }

        // Free the allocated memory
        for(int i = 0; i < arg_count; i++) {
            free(input_args[i]);
        }
        free(input_args);
    }

    return 0;
}