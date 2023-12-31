List of vulnerabilities detected: 
Error: Null Dereference   pointer `command2` last assigned on line 95 could be null and is dereferenced at line 96, column 5.
 Example: 
  94. 
  95.     Cmd command2 = malloc(sizeof(struct cmd_t));
  96.     command2->nargs = 2;
          ^
  97.     command2->maxargs = 2;
  98.     command2->args = malloc(sizeof(char*) * 3);

Error: Null Dereference   pointer `command2->args` last assigned on line 98 could be null and is dereferenced at line 99, column 5.
 Example: 
   97.     command2->maxargs = 2;
   98.     command2->args = malloc(sizeof(char*) * 3);
   99.     command2->args[0] = "grep";
           ^
  100.     command2->args[1] = "file.txt";
  101.     command2->args[2] = NULL;

Error: Null Dereference   pointer `command1` last assigned on line 86 could be null and is dereferenced at line 87, column 5.
 Example: 
  85.     // Example usage
  86.     Cmd command1 = malloc(sizeof(struct cmd_t));
  87.     command1->nargs = 3;
          ^
  88.     command1->maxargs = 3;
  89.     command1->args = malloc(sizeof(char*) * 4);

Error: Null Dereference   pointer `command1->args` last assigned on line 89 could be null and is dereferenced at line 90, column 5.
 Example: 
  88.     command1->maxargs = 3;
  89.     command1->args = malloc(sizeof(char*) * 4);
  90.     command1->args[0] = "ls";
          ^
  91.     command1->args[1] = "-l";
  92.     command1->args[2] = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 98.
 Example: 
   97.     command2->maxargs = 2;
   98.     command2->args = malloc(sizeof(char*) * 3);
   99.     command2->args[0] = "grep";
           ^
  100.     command2->args[1] = "file.txt";
  101.     command2->args[2] = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 95.
 Example: 
  94. 
  95.     Cmd command2 = malloc(sizeof(struct cmd_t));
  96.     command2->nargs = 2;
          ^
  97.     command2->maxargs = 2;
  98.     command2->args = malloc(sizeof(char*) * 3);

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 89.
 Example: 
  88.     command1->maxargs = 3;
  89.     command1->args = malloc(sizeof(char*) * 4);
  90.     command1->args[0] = "ls";
          ^
  91.     command1->args[1] = "-l";
  92.     command1->args[2] = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 86.
 Example: 
  85.     // Example usage
  86.     Cmd command1 = malloc(sizeof(struct cmd_t));
  87.     command1->nargs = 3;
          ^
  88.     command1->maxargs = 3;
  89.     command1->args = malloc(sizeof(char*) * 4);

Error: Buffer Overrun L3   Offset: [-1, +oo] Size: [0, +oo].
 Example: 
  52.             // If not the first command && j != 2 * numPipes
  53.             if (j != 0) {
  54.                 if (dup2(pipefds[j - 2], 0) < 0) {
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
    int pipefds[2 * numPipes];
    for (i = 0; i < (numPipes); i++) {
        if (pipe(pipefds + i * 2) < 0) {
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
            // If not the first command && j != 2 * numPipes
            if (j != 0) {
                if (dup2(pipefds[j - 2], 0) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            for (i = 0; i < 2 * numPipes; i++) {
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
    while ((pid = wait(&status)) > 0);
}
int main() {
    // Example usage
    Cmd command1 = malloc(sizeof(struct cmd_t));
    command1->nargs = 3;
    command1->maxargs = 3;
    command1->args = malloc(sizeof(char*) * 4);
    command1->args[0] = "ls";
    command1->args[1] = "-l";
    command1->args[2] = NULL;
    command1->next = NULL;
    Cmd command2 = malloc(sizeof(struct cmd_t));
    command2->nargs = 2;
    command2->maxargs = 2;
    command2->args = malloc(sizeof(char*) * 3);
    command2->args[0] = "grep";
    command2->args[1] = "file.txt";
    command2->args[2] = NULL;
    command2->next = NULL;
    command1->next = command2;
    executePipedCommands(command1);
    return 0;
}