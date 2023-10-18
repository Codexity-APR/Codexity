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
    int n = 0;
    char c;

    *str = strAlloc(1);

    while ((c = getchar()) != '\n') {
        (*str)[n++] = c;
        *str = realloc(*str, (n + 1) * sizeof(char));
    }

    (*str)[n] = '\0';

    return n;
}

int main() {
    Estudante estudante;

    printf("Nome: ");
    lineReader(&(estudante.nome));

    printf("Endereco: ");
    lineReader(&(estudante.endereco));

    printf("Matricula: ");
    lineReader(&(estudante.matricula));

    printf("Dados do estudante:\n");
    printf("Nome: %s\n", estudante.nome);
    printf("Endereco: %s\n", estudante.endereco);
    printf("Matricula: %s\n", estudante.matricula);

    free(estudante.nome);
    free(estudante.endereco);
    free(estudante.matricula);

    return 0;
}