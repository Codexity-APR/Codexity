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
    int i = 0;
    char c;
    *str = strAlloc(1);
    if (*str == NULL) {
        return -1;
    }
    while ((c = getchar()) != '\n') {
        (*str)[i++] = c;
        *str = realloc(*str, (i + 1) * sizeof(char));
        if (*str == NULL) {
            return -1;
        }
    }
    (*str)[i] = '\0';
    return i;
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