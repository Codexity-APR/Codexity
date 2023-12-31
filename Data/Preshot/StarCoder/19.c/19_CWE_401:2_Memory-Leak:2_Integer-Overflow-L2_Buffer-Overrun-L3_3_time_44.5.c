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
        fgets(buffer,SIZE,stdin);

        // Remove the newline character from the input buffer
        if(buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }

        // Tokenize the input buffer to get the command and its arguments
        char *token = strtok(buffer, " ");
        int i = 0;
        while(token != NULL) {
            input_args = realloc(input_args, (i + 1) * sizeof(char*));
            input_args[i] = malloc(strlen(token) + 1);
            strcpy(input_args[i], token);
            token = strtok(NULL, " ");
            i++;
        }
        input_args = realloc(input_args, (i + 1) * sizeof(char*));
        input_args[i] = NULL;

        // Execute the command
        if(fork() == 0) {
            execvp(input_args[0], input_args);
            printf("Command not found\n");
            exit(1);
        }
        else {
            wait(NULL);
        }

        // Free memory allocated for the command and its arguments
        for(int j = 0; j < i; j++) {
            free(input_args[j]);
        }
        free(input_args);
        input_args = NULL;
    }

    return 0;
}