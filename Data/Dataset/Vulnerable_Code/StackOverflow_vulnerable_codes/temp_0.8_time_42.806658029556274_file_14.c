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
    
    while (1) {
        printf("Enter command: ");
        fgets(buffer, SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        // Tokenize the input command
        int arg_count = 0;
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            input_args = realloc(input_args, (arg_count + 1) * sizeof(char *));
            input_args[arg_count] = malloc(strlen(token) + 1);
            strcpy(input_args[arg_count], token);
            arg_count++;

            token = strtok(NULL, " ");
        }
        input_args = realloc(input_args, (arg_count + 1) * sizeof(char *));
        input_args[arg_count] = NULL;

        // Fork a child process
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }

        if (pid == 0) {
            // Child process
            execvp(input_args[0], input_args);
            perror("Exec failed");
            exit(1);
        } else {
            // Parent process
            wait(NULL);
        }

        // Free the memory allocated for input_args
        for (int i = 0; i < arg_count; i++) {
            free(input_args[i]);
        }
        free(input_args);
        input_args = NULL;
    }

    return 0;
}