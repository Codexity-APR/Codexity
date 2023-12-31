#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_NUM_ARGS 256
#define SIZE 256

int main() {
    char buffer[SIZE] = "";
    char *input_args[MAX_NUM_ARGS] = {NULL}; // allocate space for an array of char pointers
    int num_args = 0; // initialize the number of arguments to 0

    while (1) {
        printf(">> ");
        fgets(buffer, SIZE, stdin); // read input from user
        num_args = 0; // reset the number of arguments to 0 for each loop

        // split input string into individual arguments
        char *token = strtok(buffer, " \n"); // split input string using space and newline delimiters
        while (token != NULL) {
            input_args[num_args++] = token;
            token = strtok(NULL, " \n");
        }
        input_args[num_args] = NULL; // set the last element of the array to NULL

        if (strcmp(input_args[0], "exit") == 0) {
            break; // exit the loop if the user enters "exit"
        }

        // execute the command using execvp()
        int pid = fork();
        if (pid == 0) {
            execvp(input_args[0], input_args);
            printf("Command '%s' not found\n", input_args[0]);
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}