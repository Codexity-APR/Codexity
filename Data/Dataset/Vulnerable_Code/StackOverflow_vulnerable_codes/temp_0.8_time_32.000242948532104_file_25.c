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
        printf("Enter a command: ");
        fflush(stdout);

        fgets(buffer, SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        // Tokenize the input command
        int num_args = 0;
        char *token = strtok(buffer, " ");
        input_args = malloc(sizeof(char *) * MAX_NUM_ARGS);

        while (token != NULL) {
            input_args[num_args] = strdup(token);
            num_args++;
            token = strtok(NULL, " ");
        }
        input_args[num_args] = NULL;

        // Execute the command
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork() failed");
            exit(1);
        } else if (pid == 0) {
            // Child process
            execvp(input_args[0], input_args);
            perror("execvp() failed");
            exit(1);
        } else {
            // Parent process
            wait(NULL);
        }

        // Free allocated memory
        for (int i = 0; i < num_args; i++) {
            free(input_args[i]);
        }
        free(input_args);
    }

    return 0;
}