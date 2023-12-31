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
        printf("Enter your command: ");
        fgets(buffer, SIZE, stdin);

        if (strlen(buffer) == 1) {
            continue;
        }

        buffer[strlen(buffer) - 1] = '\0';
        
        input_args = malloc(MAX_NUM_ARGS * sizeof(char*));
        if (input_args == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }

        char *token = strtok(buffer, " ");
        int i = 0;
        while (token != NULL) {
            input_args[i++] = token;
            token = strtok(NULL, " ");
        }
        input_args[i] = NULL;

        pid_t pid = fork();

        if (pid == -1) {
            perror("Failed to fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // child process
            execvp(input_args[0], input_args);
            perror("Failed to execute command");
            exit(EXIT_FAILURE);
        } else {
            // parent process
            int status;
            waitpid(pid, &status, 0);
            free(input_args);
        }
    }

    return 0;
}