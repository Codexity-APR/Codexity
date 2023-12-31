List of vulnerabilities detected: 
Error: Null Dereference   pointer `command3` last assigned on line 103 could be null and is dereferenced at line 104, column 5.
 Example: 
  102. 
  103.     Cmd command3 = malloc(sizeof(struct cmd_t));
  104.     command3->nargs = 1;
           ^
  105.     command3->maxargs = 1;
  106.     command3->args = malloc(command3->maxargs * sizeof(char *));

Error: Null Dereference   pointer `command3->args` last assigned on line 106 could be null and is dereferenced at line 107, column 5.
 Example: 
  105.     command3->maxargs = 1;
  106.     command3->args = malloc(command3->maxargs * sizeof(char *));
  107.     command3->args[0] = NULL;
           ^
  108. 
  109.     command1->next = command2;

Error: Null Dereference   pointer `command2` last assigned on line 96 could be null and is dereferenced at line 97, column 5.
 Example: 
  95. 
  96.     Cmd command2 = malloc(sizeof(struct cmd_t));
  97.     command2->nargs = 2;
          ^
  98.     command2->maxargs = 2;
  99.     command2->args = malloc(command2->maxargs * sizeof(char *));

Error: Null Dereference   pointer `command2->args` last assigned on line 99 could be null and is dereferenced at line 100, column 5.
 Example: 
   98.     command2->maxargs = 2;
   99.     command2->args = malloc(command2->maxargs * sizeof(char *));
  100.     command2->args[0] = "grep";
           ^
  101.     command2->args[1] = "main";
  102.

Error: Null Dereference   pointer `command1` last assigned on line 89 could be null and is dereferenced at line 90, column 5.
 Example: 
  88.     // Test command structure
  89.     Cmd command1 = malloc(sizeof(struct cmd_t));
  90.     command1->nargs = 2;
          ^
  91.     command1->maxargs = 2;
  92.     command1->args = malloc(command1->maxargs * sizeof(char *));

Error: Null Dereference   pointer `command1->args` last assigned on line 92 could be null and is dereferenced at line 93, column 5.
 Example: 
  91.     command1->maxargs = 2;
  92.     command1->args = malloc(command1->maxargs * sizeof(char *));
  93.     command1->args[0] = "ls";
          ^
  94.     command1->args[1] = NULL;
  95.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 99.
 Example: 
   98.     command2->maxargs = 2;
   99.     command2->args = malloc(command2->maxargs * sizeof(char *));
  100.     command2->args[0] = "grep";
           ^
  101.     command2->args[1] = "main";
  102.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 96.
 Example: 
  95. 
  96.     Cmd command2 = malloc(sizeof(struct cmd_t));
  97.     command2->nargs = 2;
          ^
  98.     command2->maxargs = 2;
  99.     command2->args = malloc(command2->maxargs * sizeof(char *));

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 92.
 Example: 
  91.     command1->maxargs = 2;
  92.     command1->args = malloc(command1->maxargs * sizeof(char *));
  93.     command1->args[0] = "ls";
          ^
  94.     command1->args[1] = NULL;
  95.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 89.
 Example: 
  88.     // Test command structure
  89.     Cmd command1 = malloc(sizeof(struct cmd_t));
  90.     command1->nargs = 2;
          ^
  91.     command1->maxargs = 2;
  92.     command1->args = malloc(command1->maxargs * sizeof(char *));

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 106.
 Example: 
  105.     command3->maxargs = 1;
  106.     command3->args = malloc(command3->maxargs * sizeof(char *));
  107.     command3->args[0] = NULL;
           ^
  108. 
  109.     command1->next = command2;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 103.
 Example: 
  102. 
  103.     Cmd command3 = malloc(sizeof(struct cmd_t));
  104.     command3->nargs = 1;
           ^
  105.     command3->maxargs = 1;
  106.     command3->args = malloc(command3->maxargs * sizeof(char *));

Error: Buffer Overrun L3   Offset: [-1, +oo] Size: [0, +oo].
 Example: 
  53.             // if not first command && j != 2*numPipes
  54.             if (j != 0 ) {
  55.                 if (dup2(pipefds[j-2], 0) < 0) {
                               ^
  56.                     perror(" dup2"); // If there's an error, print the error message
  57.                     exit(EXIT_FAILURE); // And exit the program with failure status


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
            // if not last command
            if (command->next) {
                if (dup2(pipefds[j + 1], 1) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            // if not first command && j != 2*numPipes
            if (j != 0 ) {
                if (dup2(pipefds[j-2], 0) < 0) {
                    perror(" dup2"); // If there's an error, print the error message
                    exit(EXIT_FAILURE); // And exit the program with failure status
                }
            }
            for (i = 0; i < 2*numPipes; i++){
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
    for (i = 0; i < 2 * numPipes; i++){
        close(pipefds[i]);
    }
    for (i = 0; i < numPipes + 1; i++){
        wait(&status);
    }
}
int main() {
    // Test command structure
    Cmd command1 = malloc(sizeof(struct cmd_t));
    command1->nargs = 2;
    command1->maxargs = 2;
    command1->args = malloc(command1->maxargs * sizeof(char *));
    command1->args[0] = "ls";
    command1->args[1] = NULL;
    Cmd command2 = malloc(sizeof(struct cmd_t));
    command2->nargs = 2;
    command2->maxargs = 2;
    command2->args = malloc(command2->maxargs * sizeof(char *));
    command2->args[0] = "grep";
    command2->args[1] = "main";
    Cmd command3 = malloc(sizeof(struct cmd_t));
    command3->nargs = 1;
    command3->maxargs = 1;
    command3->args = malloc(command3->maxargs * sizeof(char *));
    command3->args[0] = NULL;
    command1->next = command2;
    command2->next = command3;
    command3->next = NULL;
    executePipedCommands(command1);
    free(command1->args);
    free(command1);
    free(command2->args);
    free(command2);
    free(command3->args);
    free(command3);
    return 0;
}