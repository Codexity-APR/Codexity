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
    int len = 0;
    char ch;
    *str = strAlloc(1);

    if (!*str) {
        return -1;
    }

    while ((ch = getchar()) != '\n') {
        (*str)[len++] = ch;
        *str = realloc(*str, len + 1);

        if (!*str) {
            return -1;
        }
    }

    (*str)[len] = '\0';
    return len;
}

int main() {
    Estudante estudante;

    printf("Digite o nome do estudante: ");
    lineReader(&(estudante.nome));

    printf("Digite o endereco do estudante: ");
    lineReader(&(estudante.endereco));

    printf("Digite a matricula do estudante: ");
    lineReader(&(estudante.matricula));

    printf("\nDados do estudante:\n");
    printf("Nome: %s\n", estudante.nome);
    printf("Endereco: %s\n", estudante.endereco);
    printf("Matricula: %s\n", estudante.matricula);

    free(estudante.nome);
    free(estudante.endereco);
    free(estudante.matricula);

    return 0;
}