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