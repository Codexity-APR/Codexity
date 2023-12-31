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

#ifdef DEBUG
            printf("Child: args[0] = %s\n", args[0]);
            printf("Child: args[1] = %s\n", args[1]);
            printf("Child: args[2] = %s\n", args[2]);
            printf("Child: args[3] = %s\n", args[3]);
            printf("Child: args[4] = %s\n", args[4]);
            printf("Child: args[5] = %s\n", args[5]);
#endif

            // execute the command
            execvp(args[0], args);
            perror("execvp"); // print error message
            exit(1); // exit on error
        } else if (pid < 0) { // fork failed
            perror("fork");
            exit(1);
        } else { // parent process
            waitpid(pid, &status, 0); // wait for child to exit
        }
    }

    return 0;
}