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
    int max_size = 100;
    int num_chars = 0;
    char c;

    *str = strAlloc(max_size);

    if (*str == NULL) {
        return -1;
    }

    while ((c = getchar()) != '\n') {
        if (num_chars >= max_size - 1) {
            max_size *= 2;
            *str = realloc(*str, max_size);
            if (*str == NULL) {
                return -1;
            }
        }
        (*str)[num_chars++] = c;
    }

    (*str)[num_chars] = '\0';
    return num_chars;
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