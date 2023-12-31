List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 19 by call to `strAlloc()`, is not freed after the last access at line 28, column 13.
 Example: 
  26.         if (count == size) {
  27.             size *= 2;
  28.             *str = realloc(*str, (size + 1) * sizeof(char));
                  ^
  29.             if (*str == NULL) {
  30.                 printf("Memory allocation failed.\n");


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *nome;
    char *endereco;
    char *matricula;
} Estudante;
char *strAlloc(int n) {
    return (char *) malloc((n + 1) * sizeof(char));
}
int lineReader(char **str) {
    int count = 0;
    int size = 1;
    char c;
    *str = strAlloc(size);
    if (*str == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    while ((c = getchar()) != '\n') {
        (*str)[count++] = c;
        if (count == size) {
            size *= 2;
            *str = realloc(*str, (size + 1) * sizeof(char));
            if (*str == NULL) {
                printf("Memory allocation failed.\n");
                exit(1);
            }
        }
    }
    (*str)[count] = '\0';
    return count;
}
void freeEstudante(Estudante *estudante) {
    free(estudante->nome);
    free(estudante->endereco);
    free(estudante->matricula);
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
    freeEstudante(&estudante);
    return 0;
}