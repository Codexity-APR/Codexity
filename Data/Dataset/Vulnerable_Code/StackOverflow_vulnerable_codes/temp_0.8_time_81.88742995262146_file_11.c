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
    int size = 2;
    char *buffer = (char *) malloc(size * sizeof(char));
    char c;

    if (!buffer) {
        printf("Memory allocation failed!");
        return 0;
    }

    while ((c = getchar()) != '\n') {
        buffer[len++] = c;

        if (len >= size) {
            size *= 2;
            char *temp = (char *) realloc(buffer, size * sizeof(char));
            if (!temp) {
                printf("Memory reallocation failed!");
                free(buffer);
                return 0;
            }
            buffer = temp;
        }
    }

    *str = (char *) malloc((len + 1) * sizeof(char));
    if (!(*str)) {
        printf("Memory allocation failed!");
        free(buffer);
        return 0;
    }

    strncpy(*str, buffer, len);
    (*str)[len] = '\0';

    free(buffer);
    return 1;
}

int main() {
    Estudante estudante;

    printf("Digite o nome do estudante: ");
    if (!lineReader(&estudante.nome)) {
        return 1;
    }

    printf("Digite o endereco do estudante: ");
    if (!lineReader(&estudante.endereco)) {
        free(estudante.nome);
        return 1;
    }

    printf("Digite a matricula do estudante: ");
    if (!lineReader(&estudante.matricula)) {
        free(estudante.nome);
        free(estudante.endereco);
        return 1;
    }

    printf("\nDados do estudante:\n");
    printf("Nome: %s\n", estudante.nome);
    printf("Endereco: %s\n", estudante.endereco);
    printf("Matricula: %s\n", estudante.matricula);

    free(estudante.nome);
    free(estudante.endereco);
    free(estudante.matricula);

    return 0;
}