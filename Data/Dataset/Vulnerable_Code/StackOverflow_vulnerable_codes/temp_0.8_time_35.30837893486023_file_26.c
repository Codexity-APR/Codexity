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
    int arg_count = 0; // to keep track of the number of arguments

    printf("Enter a command: ");
    fgets(buffer, SIZE, stdin);

    // Remove the newline character from the end of the buffer
    buffer[strcspn(buffer, "\n")] = 0;

    // Tokenize the input to extract the arguments
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        input_args = realloc(input_args, (arg_count + 1) * sizeof(char*));
        input_args[arg_count] = malloc(strlen(token) + 1);
        strcpy(input_args[arg_count], token);
        arg_count++;
        token = strtok(NULL, " ");
    }

    // Add a NULL pointer at the end of the argument array
    input_args = realloc(input_args, (arg_count + 1) * sizeof(char*));
    input_args[arg_count] = NULL;

    // Print the arguments
    for (int i = 0; i < arg_count; i++) {
        printf("Argument %d: %s\n", i, input_args[i]);
    }

    // Free the allocated memory
    for (int i = 0; i <= arg_count; i++) {
        free(input_args[i]);
    }
    free(input_args);

    return 0;
}