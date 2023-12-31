List of vulnerabilities detected: 
Error: Null Dereference   pointer `command3` last assigned on line 90 could be null and is dereferenced at line 106, column 5.
 Example: 
  104.     command2->args[2] = NULL;
  105. 
  106.     command3->nargs = 1;
           ^
  107.     command3->maxargs = 1;
  108.     command3->args = malloc(sizeof(char*) * command3->nargs);

Error: Null Dereference   pointer `command3->args` last assigned on line 108 could be null and is dereferenced at line 109, column 5.
 Example: 
  107.     command3->maxargs = 1;
  108.     command3->args = malloc(sizeof(char*) * command3->nargs);
  109.     command3->args[0] = "wc";
           ^
  110.     command3->args[1] = NULL;
  111.

Error: Null Dereference   pointer `command2` last assigned on line 89 could be null and is dereferenced at line 99, column 5.
 Example: 
   97.     command1->args[1] = NULL;
   98. 
   99.     command2->nargs = 3;
           ^
  100.     command2->maxargs = 3;
  101.     command2->args = malloc(sizeof(char*) * command2->nargs);

Error: Null Dereference   pointer `command2->args` last assigned on line 101 could be null and is dereferenced at line 102, column 5.
 Example: 
  100.     command2->maxargs = 3;
  101.     command2->args = malloc(sizeof(char*) * command2->nargs);
  102.     command2->args[0] = "grep";
           ^
  103.     command2->args[1] = "test";
  104.     command2->args[2] = NULL;

Error: Null Dereference   pointer `command1` last assigned on line 88 could be null and is dereferenced at line 93, column 5.
 Example: 
  91. 
  92.     // Set the arguments for each command
  93.     command1->nargs = 2;
          ^
  94.     command1->maxargs = 2;
  95.     command1->args = malloc(sizeof(char*) * command1->nargs);

Error: Null Dereference   pointer `command1->args` last assigned on line 95 could be null and is dereferenced at line 96, column 5.
 Example: 
  94.     command1->maxargs = 2;
  95.     command1->args = malloc(sizeof(char*) * command1->nargs);
  96.     command1->args[0] = "ls";
          ^
  97.     command1->args[1] = NULL;
  98.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 95.
 Example: 
  94.     command1->maxargs = 2;
  95.     command1->args = malloc(sizeof(char*) * command1->nargs);
  96.     command1->args[0] = "ls";
          ^
  97.     command1->args[1] = NULL;
  98.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 90.
 Example: 
  104.     command2->args[2] = NULL;
  105. 
  106.     command3->nargs = 1;
           ^
  107.     command3->maxargs = 1;
  108.     command3->args = malloc(sizeof(char*) * command3->nargs);

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 89.
 Example: 
   97.     command1->args[1] = NULL;
   98. 
   99.     command2->nargs = 3;
           ^
  100.     command2->maxargs = 3;
  101.     command2->args = malloc(sizeof(char*) * command2->nargs);

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 88.
 Example: 
  91. 
  92.     // Set the arguments for each command
  93.     command1->nargs = 2;
          ^
  94.     command1->maxargs = 2;
  95.     command1->args = malloc(sizeof(char*) * command1->nargs);

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 108.
 Example: 
  107.     command3->maxargs = 1;
  108.     command3->args = malloc(sizeof(char*) * command3->nargs);
  109.     command3->args[0] = "wc";
           ^
  110.     command3->args[1] = NULL;
  111.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 101.
 Example: 
  100.     command2->maxargs = 3;
  101.     command2->args = malloc(sizeof(char*) * command2->nargs);
  102.     command2->args[0] = "grep";
           ^
  103.     command2->args[1] = "test";
  104.     command2->args[2] = NULL;

Error: Buffer Overrun L1   Offset: 1 Size: 1.
 Example: 
  108.     command3->args = malloc(sizeof(char*) * command3->nargs);
  109.     command3->args[0] = "wc";
  110.     command3->args[1] = NULL;
           ^
  111. 
  112.     // Link the commands together

Error: Buffer Overrun L3   Offset: [-1, +oo] Size: [0, +oo].
 Example: 
  53.             //if not first command && j!= 2*numPipes
  54.             if (j != 0 ) {
  55.                 if (dup2(pipefds[j-2], 0) < 0) {
                               ^
  56.                     perror(" dup2");
  57.                     exit(EXIT_FAILURE);


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
            //if not last command
            if (command->next) {
                if (dup2(pipefds[j + 1], 1) < 0) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            //if not first command && j!= 2*numPipes
            if (j != 0 ) {
                if (dup2(pipefds[j-2], 0) < 0) {
                    perror(" dup2");
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
    for (i = 0; i < numPipes + 1; i++)
        wait(&status);
}
int main() {
    // Create the command structure
    Cmd command1 = malloc(sizeof(struct cmd_t));
    Cmd command2 = malloc(sizeof(struct cmd_t));
    Cmd command3 = malloc(sizeof(struct cmd_t));
    // Set the arguments for each command
    command1->nargs = 2;
    command1->maxargs = 2;
    command1->args = malloc(sizeof(char*) * command1->nargs);
    command1->args[0] = "ls";
    command1->args[1] = NULL;
    command2->nargs = 3;
    command2->maxargs = 3;
    command2->args = malloc(sizeof(char*) * command2->nargs);
    command2->args[0] = "grep";
    command2->args[1] = "test";
    command2->args[2] = NULL;
    command3->nargs = 1;
    command3->maxargs = 1;
    command3->args = malloc(sizeof(char*) * command3->nargs);
    command3->args[0] = "wc";
    command3->args[1] = NULL;
    // Link the commands together
    command1->next = command2;
    command2->next = command3;
    command3->next = NULL;
    // Execute the piped commands
    executePipedCommands(command1);
    // Free the memory
    free(command1->args);
    free(command1);
    free(command2->args);
    free(command2);
    free(command3->args);
    free(command3);
    return 0;
}