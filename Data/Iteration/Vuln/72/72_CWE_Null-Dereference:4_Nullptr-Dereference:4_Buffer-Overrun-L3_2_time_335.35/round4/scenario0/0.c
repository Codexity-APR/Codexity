List of vulnerabilities detected: 
Error: Null Dereference   pointer `command2` last assigned on line 96 could be null and is dereferenced at line 97, column 5.
 Example: 
  95. 
  96.     Cmd command2 = (Cmd)malloc(sizeof(struct cmd_t));
  97.     command2->nargs = 3;
          ^
  98.     command2->maxargs = 3;
  99.     command2->args = (char**)malloc(sizeof(char*) * 4);

Error: Null Dereference   pointer `command2->args` last assigned on line 99 could be null and is dereferenced at line 100, column 5.
 Example: 
   98.     command2->maxargs = 3;
   99.     command2->args = (char**)malloc(sizeof(char*) * 4);
  100.     command2->args[0] = "grep";
           ^
  101.     command2->args[1] = "file";
  102.     command2->args[2] = "-i";

Error: Null Dereference   pointer `command1` last assigned on line 88 could be null and is dereferenced at line 89, column 5.
 Example: 
  87.     // Example usage of the executePipedCommands function
  88.     Cmd command1 = (Cmd)malloc(sizeof(struct cmd_t));
  89.     command1->nargs = 2;
          ^
  90.     command1->maxargs = 2;
  91.     command1->args = (char**)malloc(sizeof(char*) * 3);

Error: Null Dereference   pointer `command1->args` last assigned on line 91 could be null and is dereferenced at line 92, column 5.
 Example: 
  90.     command1->maxargs = 2;
  91.     command1->args = (char**)malloc(sizeof(char*) * 3);
  92.     command1->args[0] = "ls";
          ^
  93.     command1->args[1] = "-l";
  94.     command1->args[2] = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 99.
 Example: 
   98.     command2->maxargs = 3;
   99.     command2->args = (char**)malloc(sizeof(char*) * 4);
  100.     command2->args[0] = "grep";
           ^
  101.     command2->args[1] = "file";
  102.     command2->args[2] = "-i";

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 96.
 Example: 
  95. 
  96.     Cmd command2 = (Cmd)malloc(sizeof(struct cmd_t));
  97.     command2->nargs = 3;
          ^
  98.     command2->maxargs = 3;
  99.     command2->args = (char**)malloc(sizeof(char*) * 4);

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 91.
 Example: 
  90.     command1->maxargs = 2;
  91.     command1->args = (char**)malloc(sizeof(char*) * 3);
  92.     command1->args[0] = "ls";
          ^
  93.     command1->args[1] = "-l";
  94.     command1->args[2] = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 88.
 Example: 
  87.     // Example usage of the executePipedCommands function
  88.     Cmd command1 = (Cmd)malloc(sizeof(struct cmd_t));
  89.     command1->nargs = 2;
          ^
  90.     command1->maxargs = 2;
  91.     command1->args = (char**)malloc(sizeof(char*) * 3);

Error: Buffer Overrun L3   Offset: [-1, +oo] Size: [0, +oo].
 Example: 
  52.             // if not first command && j != 2*numPipes
  53.             if (j != 0) {
  54.                 if (dup2(pipefds[j-2], 0) < 0) {
                               ^
  55.                     perror("dup2");
  56.                     exit(EXIT_FAILURE);


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
    printf("number of pipes: %d\n", numPipes);
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
            // if not last command
            if (command->next) {
                if (dup2(pipefds[j + 1], 1) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            // if not first command && j != 2*numPipes
            if (j != 0) {
                if (dup2(pipefds[j-2], 0) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            for (i = 0; i < 2*numPipes; i++) {
                close(pipefds[i]);
            }
            if (execvp(command->args[0], command->args) < 0) {
                perror(command->args[0]);
                exit(EXIT_FAILURE);
            }
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
    // Example usage of the executePipedCommands function
    Cmd command1 = (Cmd)malloc(sizeof(struct cmd_t));
    command1->nargs = 2;
    command1->maxargs = 2;
    command1->args = (char**)malloc(sizeof(char*) * 3);
    command1->args[0] = "ls";
    command1->args[1] = "-l";
    command1->args[2] = NULL;
    Cmd command2 = (Cmd)malloc(sizeof(struct cmd_t));
    command2->nargs = 3;
    command2->maxargs = 3;
    command2->args = (char**)malloc(sizeof(char*) * 4);
    command2->args[0] = "grep";
    command2->args[1] = "file";
    command2->args[2] = "-i";
    command2->args[3] = NULL;
    command1->next = command2;
    command2->next = NULL;
    executePipedCommands(command1);
    free(command1->args);
    free(command1);
    free(command2->args);
    free(command2);
    return 0;
}