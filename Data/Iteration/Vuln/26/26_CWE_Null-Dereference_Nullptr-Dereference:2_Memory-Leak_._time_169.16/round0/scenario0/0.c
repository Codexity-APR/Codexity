List of vulnerabilities detected: 
Error: Null Dereference   pointer `*str` last assigned on line 20 could be null and is dereferenced at line 23, column 9.
 Example: 
  21. 
  22.     while ((c = getchar()) != '\n') {
  23.         (*str)[count++] = c;
              ^
  24. 
  25.         if (count == size) {

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 20 indirectly during the call to `strAlloc()`.
 Example: 
  29.     }
  30. 
  31.     (*str)[count] = '\0';
          ^
  32. 
  33.     return count;

Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 20 indirectly during the call to `strAlloc()`.
 Example: 
  21. 
  22.     while ((c = getchar()) != '\n') {
  23.         (*str)[count++] = c;
              ^
  24. 
  25.         if (count == size) {

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 20 by call to `strAlloc()`, is not freed after the last access at line 27, column 13.
 Example: 
  25.         if (count == size) {
  26.             size *= 2;
  27.             *str = realloc(*str, size);
                  ^
  28.         }
  29.     }


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
    int count = 0;
    int size = 1;
    char c;
    *str = strAlloc(size);
    while ((c = getchar()) != '\n') {
        (*str)[count++] = c;
        if (count == size) {
            size *= 2;
            *str = realloc(*str, size);
        }
    }
    (*str)[count] = '\0';
    return count;
}
int main() {
    Estudante estudante;
    printf("Digite o nome do estudante: ");
    lineReader(&(estudante.nome));
    printf("Digite o endereco do estudante: ");
    lineReader(&(estudante.endereco));
    printf("Digite a matricula do estudante: ");
    lineReader(&(estudante.matricula));
    printf("Nome: %s\n", estudante.nome);
    printf("Endereco: %s\n", estudante.endereco);
    printf("Matricula: %s\n", estudante.matricula);
    free(estudante.nome);
    free(estudante.endereco);
    free(estudante.matricula);
    return 0;
}