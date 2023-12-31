List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 17 by call to `strAlloc()`, is not freed after the last access at line 26, column 9.
 Example: 
  24.     while ((c = getchar()) != '\n' && c != EOF) {
  25.         (*str)[i++] = c;
  26.         *str = realloc(*str, (i + 1) * sizeof(char));
              ^
  27.         
  28.         if (*str == NULL) {


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
    free(estudante.nome);
    free(estudante.endereco);
    free(estudante.matricula);
    return 0;
}