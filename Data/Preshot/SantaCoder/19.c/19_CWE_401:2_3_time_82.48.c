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
        buffer[strcspn(buffer, "\n")] = '\0'; // remove trailing newline character

        if (strlen(buffer) == 0) { // empty input
            continue;
        }

        // tokenize the input command
        char *token = strtok(buffer, " ");
        int num_args = 0;
        while (token != NULL) {
            input_args = realloc(input_args, sizeof(char*) * (num_args + 1));
            input_args[num_args] = token;
            num_args++;
            token = strtok(NULL, " ");
        }
        input_args = realloc(input_args, sizeof(char*) * (num_args + 1));
        input_args[num_args] = NULL;

        // execute the command with arguments
        if (fork() == 0) {
            execvp(input_args[0], input_args);
            // if execvp returns, it means the command failed to execute
            printf("Failed to execute command: %s\n", input_args[0]);
            exit(1);
        } else {
            wait(NULL);
        }

        // free input_args for the next loop iteration
        free(input_args);
        input_args = NULL;
    }

    return 0;
}