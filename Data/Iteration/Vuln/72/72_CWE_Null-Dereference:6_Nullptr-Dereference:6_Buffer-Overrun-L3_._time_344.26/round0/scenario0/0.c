List of vulnerabilities detected: 
Error: Null Dereference   pointer `cmd3` last assigned on line 103 could be null and is dereferenced at line 104, column 5.
 Example: 
  102. 
  103.     Cmd cmd3 = malloc(sizeof(struct cmd_t));
  104.     cmd3->nargs = 1;
           ^
  105.     cmd3->maxargs = 1;
  106.     cmd3->args = malloc(sizeof(char*));

Error: Null Dereference   pointer `cmd3->args` last assigned on line 106 could be null and is dereferenced at line 107, column 5.
 Example: 
  105.     cmd3->maxargs = 1;
  106.     cmd3->args = malloc(sizeof(char*));
  107.     cmd3->args[0] = NULL;
           ^
  108. 
  109.     cmd1->next = cmd2;

Error: Null Dereference   pointer `cmd2` last assigned on line 96 could be null and is dereferenced at line 97, column 5.
 Example: 
  95. 
  96.     Cmd cmd2 = malloc(sizeof(struct cmd_t));
  97.     cmd2->nargs = 2;
          ^
  98.     cmd2->maxargs = 2;
  99.     cmd2->args = malloc(2 * sizeof(char*));

Error: Null Dereference   pointer `cmd2->args` last assigned on line 99 could be null and is dereferenced at line 100, column 5.
 Example: 
   98.     cmd2->maxargs = 2;
   99.     cmd2->args = malloc(2 * sizeof(char*));
  100.     cmd2->args[0] = "grep";
           ^
  101.     cmd2->args[1] = "example";
  102.

Error: Null Dereference   pointer `cmd1` last assigned on line 89 could be null and is dereferenced at line 90, column 5.
 Example: 
  88.     // Sample usage
  89.     Cmd cmd1 = malloc(sizeof(struct cmd_t));
  90.     cmd1->nargs = 2;
          ^
  91.     cmd1->maxargs = 2;
  92.     cmd1->args = malloc(2 * sizeof(char*));

Error: Null Dereference   pointer `cmd1->args` last assigned on line 92 could be null and is dereferenced at line 93, column 5.
 Example: 
  91.     cmd1->maxargs = 2;
  92.     cmd1->args = malloc(2 * sizeof(char*));
  93.     cmd1->args[0] = "ls";
          ^
  94.     cmd1->args[1] = NULL;
  95.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 99.
 Example: 
   98.     cmd2->maxargs = 2;
   99.     cmd2->args = malloc(2 * sizeof(char*));
  100.     cmd2->args[0] = "grep";
           ^
  101.     cmd2->args[1] = "example";
  102.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 96.
 Example: 
  95. 
  96.     Cmd cmd2 = malloc(sizeof(struct cmd_t));
  97.     cmd2->nargs = 2;
          ^
  98.     cmd2->maxargs = 2;
  99.     cmd2->args = malloc(2 * sizeof(char*));

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 92.
 Example: 
  91.     cmd1->maxargs = 2;
  92.     cmd1->args = malloc(2 * sizeof(char*));
  93.     cmd1->args[0] = "ls";
          ^
  94.     cmd1->args[1] = NULL;
  95.

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 89.
 Example: 
  88.     // Sample usage
  89.     Cmd cmd1 = malloc(sizeof(struct cmd_t));
  90.     cmd1->nargs = 2;
          ^
  91.     cmd1->maxargs = 2;
  92.     cmd1->args = malloc(2 * sizeof(char*));

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 106.
 Example: 
  105.     cmd3->maxargs = 1;
  106.     cmd3->args = malloc(sizeof(char*));
  107.     cmd3->args[0] = NULL;
           ^
  108. 
  109.     cmd1->next = cmd2;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 103.
 Example: 
  102. 
  103.     Cmd cmd3 = malloc(sizeof(struct cmd_t));
  104.     cmd3->nargs = 1;
           ^
  105.     cmd3->maxargs = 1;
  106.     cmd3->args = malloc(sizeof(char*));

Error: Buffer Overrun L3   Offset: [-1, +oo] Size: [0, +oo].
 Example: 
  53.             //if not first command && j!= 2*numPipes
  54.             if (j != 0 ) {
  55.                 if (dup2(pipefds[j-2], 0) < 0) {
                               ^
  56.                     perror("dup2");
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
                    perror("dup2");
                    exit(EXIT_FAILURE);
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
            perror("fork");
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
    // Sample usage
    Cmd cmd1 = malloc(sizeof(struct cmd_t));
    cmd1->nargs = 2;
    cmd1->maxargs = 2;
    cmd1->args = malloc(2 * sizeof(char*));
    cmd1->args[0] = "ls";
    cmd1->args[1] = NULL;
    Cmd cmd2 = malloc(sizeof(struct cmd_t));
    cmd2->nargs = 2;
    cmd2->maxargs = 2;
    cmd2->args = malloc(2 * sizeof(char*));
    cmd2->args[0] = "grep";
    cmd2->args[1] = "example";
    Cmd cmd3 = malloc(sizeof(struct cmd_t));
    cmd3->nargs = 1;
    cmd3->maxargs = 1;
    cmd3->args = malloc(sizeof(char*));
    cmd3->args[0] = NULL;
    cmd1->next = cmd2;
    cmd2->next = cmd3;
    cmd3->next = NULL;
    executePipedCommands(cmd1);
    return 0;
}