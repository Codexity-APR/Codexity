List of vulnerabilities detected: 
Error: Null Dereference   pointer `command2` last assigned on line 90 could be null and is dereferenced at line 91, column 5.
 Example: 
  89.     
  90.     Cmd command2 = malloc(sizeof(struct cmd_t));
  91.     command2->nargs = 2;
          ^
  92.     command2->maxargs = 2;
  93.     command2->args = malloc(sizeof(char*) * command2->maxargs);

Error: Null Dereference   pointer `command2->args` last assigned on line 93 could be null and is dereferenced at line 94, column 5.
 Example: 
  92.     command2->maxargs = 2;
  93.     command2->args = malloc(sizeof(char*) * command2->maxargs);
  94.     command2->args[0] = "grep";
          ^
  95.     command2->args[1] = "test";
  96.     command2->args[2] = NULL;

Error: Null Dereference   pointer `command1` last assigned on line 82 could be null and is dereferenced at line 83, column 5.
 Example: 
  81.     // Test code
  82.     Cmd command1 = malloc(sizeof(struct cmd_t));
  83.     command1->nargs = 3;
          ^
  84.     command1->maxargs = 3;
  85.     command1->args = malloc(sizeof(char*) * command1->maxargs);

Error: Null Dereference   pointer `command1->args` last assigned on line 85 could be null and is dereferenced at line 86, column 5.
 Example: 
  84.     command1->maxargs = 3;
  85.     command1->args = malloc(sizeof(char*) * command1->maxargs);
  86.     command1->args[0] = "ls";
          ^
  87.     command1->args[1] = "-la";
  88.     command1->args[2] = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 93.
 Example: 
  92.     command2->maxargs = 2;
  93.     command2->args = malloc(sizeof(char*) * command2->maxargs);
  94.     command2->args[0] = "grep";
          ^
  95.     command2->args[1] = "test";
  96.     command2->args[2] = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 90.
 Example: 
  89.     
  90.     Cmd command2 = malloc(sizeof(struct cmd_t));
  91.     command2->nargs = 2;
          ^
  92.     command2->maxargs = 2;
  93.     command2->args = malloc(sizeof(char*) * command2->maxargs);

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 85.
 Example: 
  84.     command1->maxargs = 3;
  85.     command1->args = malloc(sizeof(char*) * command1->maxargs);
  86.     command1->args[0] = "ls";
          ^
  87.     command1->args[1] = "-la";
  88.     command1->args[2] = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 82.
 Example: 
  81.     // Test code
  82.     Cmd command1 = malloc(sizeof(struct cmd_t));
  83.     command1->nargs = 3;
          ^
  84.     command1->maxargs = 3;
  85.     command1->args = malloc(sizeof(char*) * command1->maxargs);

Error: Buffer Overrun L1   Offset: 2 Size: 2.
 Example: 
  94.     command2->args[0] = "grep";
  95.     command2->args[1] = "test";
  96.     command2->args[2] = NULL;
          ^
  97.     
  98.     command1->next = command2;

Error: Buffer Overrun L3   Offset: [-1, +oo] Size: [0, +oo].
 Example: 
  49.             // If not the first command && j != 2*numPipes
  50.             if (j != 0) {
  51.                 if (dup2(pipefds[j-2], 0) < 0) {
                               ^
  52.                     perror("dup2");
  53.                     exit(EXIT_FAILURE);


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
struct cmd_t {
    int nargs, maxargs;
    char **args;
    struct cmd_t *next;
};
typedef struct cmd_t *Cmd;
void executePipedCommands(Cmd command) {
    int numPipes = 0;
    Cmd temp = command;
    int status;
    int i = 0;
    pid_t pid;
    while (command != NULL) {
        numPipes++;
        command = command->next;
    }
    printf("number of pipes : %d\n", numPipes);
    int pipefds[2*numPipes];
    for (i = 0; i < (numPipes); i++) {
        if (pipe(pipefds + i*2) < 0) {
            perror("couldn't pipe");
            exit(EXIT_FAILURE);
        }
    }
    int j = 0;
    command = temp;
    while (command) {
        pid = fork();
        if (pid == 0) {
            // If not the last command
            if (command->next) {
                if (dup2(pipefds[j + 1], 1) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            // If not the first command && j != 2*numPipes
            if (j != 0) {
                if (dup2(pipefds[j-2], 0) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            for (i = 0; i < 2*numPipes; i++) {
                close(pipefds[i]);
            }
            execvp(command->args[0], command->args);
            perror(command->args[0]);
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("error");
            exit(EXIT_FAILURE);
        }
        command = command->next;
        j += 2;
    }
    for (i = 0; i < 2 * numPipes; i++) {
        close(pipefds[i]);
    }
    for (i = 0; i < numPipes + 1; i++) {
        wait(&status);
    }
}
int main() {
    // Test code
    Cmd command1 = malloc(sizeof(struct cmd_t));
    command1->nargs = 3;
    command1->maxargs = 3;
    command1->args = malloc(sizeof(char*) * command1->maxargs);
    command1->args[0] = "ls";
    command1->args[1] = "-la";
    command1->args[2] = NULL;
    Cmd command2 = malloc(sizeof(struct cmd_t));
    command2->nargs = 2;
    command2->maxargs = 2;
    command2->args = malloc(sizeof(char*) * command2->maxargs);
    command2->args[0] = "grep";
    command2->args[1] = "test";
    command2->args[2] = NULL;
    command1->next = command2;
    command2->next = NULL;
    executePipedCommands(command1);
    return 0;
}