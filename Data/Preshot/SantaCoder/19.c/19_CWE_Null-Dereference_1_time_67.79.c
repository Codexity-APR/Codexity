#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_NUM_ARGS 256
#define SIZE 256

int main() {
    char buffer[SIZE] = "";
    char *input_args[MAX_NUM_ARGS] = {NULL};
    int i, num_args;
    
    while (1) {
        printf("Enter a command: ");
        fgets(buffer, SIZE, stdin);
        num_args = 0;
        input_args[num_args] = strtok(buffer, " \n");
        
        while (input_args[num_args] != NULL && num_args < MAX_NUM_ARGS - 1) {
            num_args++;
            input_args[num_args] = strtok(NULL, " \n");
        }
        
        input_args[num_args] = NULL;
        
        if (strcmp(input_args[0], "exit") == 0) {
            break;
        }
        
        if (fork() == 0) {
            execvp(input_args[0], input_args);
            printf("Unknown command\n");
            exit(1);
        }
        else {
            wait(NULL);
        }
    }
    
    return 0;
}