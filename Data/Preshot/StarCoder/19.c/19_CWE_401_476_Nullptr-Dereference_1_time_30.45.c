#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_NUM_ARGS 256
#define SIZE 256

int main() {
    char buffer[SIZE];
    char **input_args = NULL;

    // Read user input
    printf("Enter a command: ");
    fgets(buffer, SIZE, stdin);

    // Parse user input into individual arguments
    char *token = strtok(buffer, " \n");
    int num_args = 0;
    while (token != NULL && num_args < MAX_NUM_ARGS - 1) {
        input_args = realloc(input_args, (num_args + 2) * sizeof(char *));
        input_args[num_args] = token;
        token = strtok(NULL, " \n");
        num_args++;
    }
    input_args[num_args] = NULL;

    // Example usage: print out parsed arguments
    for (int i = 0; i < num_args; i++) {
        printf("Argument %d: %s\n", i, input_args[i]);
    }

    // Clean up
    free(input_args);

    return 0;
}