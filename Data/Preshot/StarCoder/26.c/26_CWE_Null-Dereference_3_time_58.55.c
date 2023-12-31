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
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (*str != NULL) {
        free(*str);
        *str = NULL;
    }

    if ((read = getline(&line, &len, stdin)) != -1) {
        *str = strAlloc(read);
        strncpy(*str, line, read - 1);
        return 1;
    }
    return 0;
}

int main() {
    Estudante estudante;
    char *nome = NULL;
    char *endereco = NULL;
    char *matricula = NULL;
    int i;

    for (i = 0; i < 1000000; i++) {
        if (!lineReader(&nome)) {
            break;
        }
        if (!lineReader(&endereco)) {
            break;
        }
        if (!lineReader(&matricula)) {
            break;
        }
        estudante.nome = nome;
        estudante.endereco = endereco;
        estudante.matricula = matricula;
        printf("%s\n", estudante.nome);
        printf("%s\n", estudante.endereco);
        printf("%s\n", estudante.matricula);
    }

    if (nome != NULL) {
        free(nome);
        nome = NULL;
    }
    if (endereco != NULL) {
        free(endereco);
        endereco = NULL;
    }
    if (matricula != NULL) {
        free(matricula);
        matricula = NULL;
    }

    return 0;
}