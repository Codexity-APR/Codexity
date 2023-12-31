#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

int main() {
    char cmd[MAX_CMD_LENGTH]; // buffer to hold user input
    char* args[MAX_ARGS]; // array of strings to hold command arguments
    int status; // exit status of child process

    while (1) {
        printf("[Enter command]> ");
        fgets(cmd, MAX_CMD_LENGTH, stdin); // read user input
        cmd[strcspn(cmd, "\n")] = '\0'; // remove trailing newline

        // check for exit command
        if (strcmp(cmd, "exit") == 0) {
            break;
        }

        pid_t pid = fork(); // create a new process

        if (pid == 0) { // child process
            // tokenize the command into arguments
            char* token = strtok(cmd, " ");
            int i = 0;
            while (token != NULL && i < MAX_ARGS) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
          
            args[i] = NULL; // set the last argument as NULL to terminate the argument array

            execvp(args[0], args); // execute the command

            perror("Exec failed"); // execvp only returns if an error occurs
            exit(1);
        } else if (pid < 0) { // error occurred during fork
            perror("Fork failed");
            exit(1);
        } else { // parent process
            waitpid(pid, &status, 0); // wait for the child process to finish
        }
    }

    return 0;
}