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
            args[i] = NULL; // add NULL pointer to indicate end of array

            // execute the command
            execvp(args[0], args);
            perror("execvp"); // print error message if execvp fails
            exit(EXIT_FAILURE); // exit child process with failure status
        } else { // parent process
            // wait for child process to exit
            status = waitpid(pid, &status, 0);

            if (status == 0) { // child process exited normally
                printf("Child process exited normally with status %d\n", WEXITSTATUS(status));
            } else { // child process exited abnormally
                printf("Child process exited abnormally with status %d\n", status);
            }
        }
    }

    return 0;
}