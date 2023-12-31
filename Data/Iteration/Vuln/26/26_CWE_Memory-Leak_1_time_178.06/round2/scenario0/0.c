List of vulnerabilities detected: 
Error: Use After Free   Pulse found a potential null pointer dereference  on line 52 indirectly during the call to `freeEstudante()`.
 Example: 
  55.     free(estudante.nome);
  56.     free(estudante.endereco);
  57.     free(estudante.matricula);
          ^
  58. 
  59.     return 0;

Error: Use After Free   Pulse found a potential null pointer dereference  on line 52 indirectly during the call to `freeEstudante()`.
 Example: 
  54.     // Free the dynamically allocated memory
  55.     free(estudante.nome);
  56.     free(estudante.endereco);
          ^
  57.     free(estudante.matricula);
  58.

Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 17 by call to `strAlloc()`, is not freed after the last access at line 24, column 9.
 Example: 
  22.     while ((c = getchar()) != '\n' && c != EOF) {
  23.         (*str)[i++] = c;
  24.         *str = realloc(*str, (i + 1) * sizeof(char));
              ^
  25.         if (*str == NULL) {
  26.             printf("Memory allocation error!");


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
    int c, i = 0;
    *str = strAlloc(1);
    if (*str == NULL) {
        printf("Memory allocation error!");
        return 0;
    }
    while ((c = getchar()) != '\n' && c != EOF) {
        (*str)[i++] = c;
        *str = realloc(*str, (i + 1) * sizeof(char));
        if (*str == NULL) {
            printf("Memory allocation error!");
            return 0;
        }
    }
    (*str)[i] = '\0';
    return 1;
}
void freeEstudante(Estudante *estudante) {
    free(estudante->nome);
    free(estudante->endereco);
    free(estudante->matricula);
}
int main() {
    Estudante estudante;
    printf("Digite o nome do estudante: ");
    lineReader(&estudante.nome);
    printf("Digite o endereco do estudante: ");
    lineReader(&estudante.endereco);
    printf("Digite a matricula do estudante: ");
    lineReader(&estudante.matricula);
    printf("\nDados do estudante:\n");
    printf("Nome: %s\n", estudante.nome);
    printf("Endereco: %s\n", estudante.endereco);
    printf("Matricula: %s\n", estudante.matricula);
    freeEstudante(&estudante);
    // Free the dynamically allocated memory
    free(estudante.nome);
    free(estudante.endereco);
    free(estudante.matricula);
    return 0;
}