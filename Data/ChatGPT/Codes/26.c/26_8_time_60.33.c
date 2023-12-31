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
    int bufferSize = 256;
    int length = 0;
    int c;

    *str = strAlloc(bufferSize);

    if (*str == NULL) {
        return -1; // Failed to allocate memory
    }

    while ((c = getchar()) != '\n') {
        (*str)[length] = c;
        length++;

        if (length == bufferSize - 1) {
            bufferSize *= 2;
            *str = realloc(*str, bufferSize);

            if (*str == NULL) {
                return -1; // Failed to reallocate memory
            }
        }
    }

    (*str)[length] = '\0';
    return length;
}

int main() {
    Estudante estudante;
    int result;

    printf("Nome: ");
    result = lineReader(&estudante.nome);

    if (result == -1) {
        printf("Failed to allocate memory for nome\n");
        return 1;
    }

    printf("Endereco: ");
    result = lineReader(&estudante.endereco);

    if (result == -1) {
        printf("Failed to allocate memory for endereco\n");
        free(estudante.nome);
        return 1;
    }

    printf("Matricula: ");
    result = lineReader(&estudante.matricula);

    if (result == -1) {
        printf("Failed to allocate memory for matricula\n");
        free(estudante.nome);
        free(estudante.endereco);
        return 1;
    }

    printf("\nEstudante:\n");
    printf("Nome: %s\n", estudante.nome);
    printf("Endereco: %s\n", estudante.endereco);
    printf("Matricula: %s\n", estudante.matricula);

    free(estudante.nome);
    free(estudante.endereco);
    free(estudante.matricula);

    return 0;
}