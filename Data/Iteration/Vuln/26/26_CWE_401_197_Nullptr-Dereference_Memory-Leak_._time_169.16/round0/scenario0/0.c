List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 18 indirectly during the call to `strAlloc()`.
 Example: 
  28.     }
  29. 
  30.     line[size] = '\0';
          ^
  31.     *str = line;
  32.     return size;

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 18 by call to `strAlloc()`, is not freed after the last access at line 24, column 13.
 Example: 
  22.         if (size + 1 >= capacity) {
  23.             capacity *= 2;
  24.             line = realloc(line, capacity * sizeof(char));
                  ^
  25.         }
  26.         line[size++] = c;

 Error type: CWE-401 at line: 24. Error message: Common realloc mistake: 'line' nulled but not freed upon failure

 Error type: CWE-197 at line: 21. Error message: Storing getchar() return value in char variable and then comparing with EOF.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *nome;
    char *endereco;
    char *matricula;
} Estudante;
char *strAlloc(int n) {
    return (char *) malloc(n * sizeof(char));
}
int lineReader(char **str) {
    int size = 0;
    int capacity = 1;
    char *line = strAlloc(capacity);
    char c = getchar();
    while (c != '\n' && c != EOF) {
        if (size + 1 >= capacity) {
            capacity *= 2;
            line = realloc(line, capacity * sizeof(char));
        }
        line[size++] = c;
        c = getchar();
    }
    line[size] = '\0';
    *str = line;
    return size;
}
int main() {
    Estudante estudante;
    printf("Digite o nome do estudante: ");
    lineReader(&estudante.nome);
    printf("Digite o endereco do estudante: ");
    lineReader(&estudante.endereco);
    printf("Digite a matricula do estudante: ");
    lineReader(&estudante.matricula);
    printf("\nInformacoes do estudante:\n");
    printf("Nome: %s\n", estudante.nome);
    printf("Endereco: %s\n", estudante.endereco);
    printf("Matricula: %s\n", estudante.matricula);
    free(estudante.nome);
    free(estudante.endereco);
    free(estudante.matricula);
    return 0;
}