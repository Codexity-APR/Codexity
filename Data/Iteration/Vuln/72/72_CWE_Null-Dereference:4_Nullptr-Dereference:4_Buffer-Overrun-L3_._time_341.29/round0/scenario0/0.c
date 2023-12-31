List of vulnerabilities detected: 
Error: Null Dereference   pointer `cmd2` last assigned on line 100 could be null and is dereferenced at line 101, column 5.
 Example: 
   99. 
  100.     Cmd cmd2 = malloc(sizeof(struct cmd_t));
  101.     cmd2->nargs = 2;
           ^
  102.     cmd2->maxargs = 2;
  103.     cmd2->args = malloc(sizeof(char *) * cmd2->maxargs);

Error: Null Dereference   pointer `cmd2->args` last assigned on line 103 could be null and is dereferenced at line 104, column 5.
 Example: 
  102.     cmd2->maxargs = 2;
  103.     cmd2->args = malloc(sizeof(char *) * cmd2->maxargs);
  104.     cmd2->args[0] = "grep";
           ^
  105.     cmd2->args[1] = "pattern";
  106.     cmd2->next = NULL;

Error: Null Dereference   pointer `cmd1` last assigned on line 92 could be null and is dereferenced at line 93, column 5.
 Example: 
  91.     // Initialize commands
  92.     Cmd cmd1 = malloc(sizeof(struct cmd_t));
  93.     cmd1->nargs = 2;
          ^
  94.     cmd1->maxargs = 2;
  95.     cmd1->args = malloc(sizeof(char *) * cmd1->maxargs);

Error: Null Dereference   pointer `cmd1->args` last assigned on line 95 could be null and is dereferenced at line 96, column 5.
 Example: 
  94.     cmd1->maxargs = 2;
  95.     cmd1->args = malloc(sizeof(char *) * cmd1->maxargs);
  96.     cmd1->args[0] = "ls";
          ^
  97.     cmd1->args[1] = NULL;
  98.     cmd1->next = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 95.
 Example: 
  94.     cmd1->maxargs = 2;
  95.     cmd1->args = malloc(sizeof(char *) * cmd1->maxargs);
  96.     cmd1->args[0] = "ls";
          ^
  97.     cmd1->args[1] = NULL;
  98.     cmd1->next = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 92.
 Example: 
  91.     // Initialize commands
  92.     Cmd cmd1 = malloc(sizeof(struct cmd_t));
  93.     cmd1->nargs = 2;
          ^
  94.     cmd1->maxargs = 2;
  95.     cmd1->args = malloc(sizeof(char *) * cmd1->maxargs);

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 103.
 Example: 
  102.     cmd2->maxargs = 2;
  103.     cmd2->args = malloc(sizeof(char *) * cmd2->maxargs);
  104.     cmd2->args[0] = "grep";
           ^
  105.     cmd2->args[1] = "pattern";
  106.     cmd2->next = NULL;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 100.
 Example: 
   99. 
  100.     Cmd cmd2 = malloc(sizeof(struct cmd_t));
  101.     cmd2->nargs = 2;
           ^
  102.     cmd2->maxargs = 2;
  103.     cmd2->args = malloc(sizeof(char *) * cmd2->maxargs);

Error: Buffer Overrun L3   Offset: [-1, +oo] Size: [0, +oo].
 Example: 
  53.             //if not first command && j!= 2*numPipes
  54.             if (j != 0 ) {
  55.                 if(dup2(pipefds[j-2], 0) < 0){
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
                if(dup2(pipefds[j-2], 0) < 0){
                    perror("dup2"); 
                    exit(EXIT_FAILURE);
                }
            }
            for(i = 0; i < 2*numPipes; i++){
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
    for(i = 0; i < 2 * numPipes; i++){
        close(pipefds[i]);
    }
    for(i = 0; i < numPipes + 1; i++){
        wait(&status);
    }
}
int main() {
    // Example usage of executePipedCommands()
    // Initialize commands
    Cmd cmd1 = malloc(sizeof(struct cmd_t));
    cmd1->nargs = 2;
    cmd1->maxargs = 2;
    cmd1->args = malloc(sizeof(char *) * cmd1->maxargs);
    cmd1->args[0] = "ls";
    cmd1->args[1] = NULL;
    cmd1->next = NULL;
    Cmd cmd2 = malloc(sizeof(struct cmd_t));
    cmd2->nargs = 2;
    cmd2->maxargs = 2;
    cmd2->args = malloc(sizeof(char *) * cmd2->maxargs);
    cmd2->args[0] = "grep";
    cmd2->args[1] = "pattern";
    cmd2->next = NULL;
    // Link commands together
    cmd1->next = cmd2;
    // Execute piped commands
    executePipedCommands(cmd1);
    return 0;
}