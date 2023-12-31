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
    if ((read = getline(&line, &len, stdin)) == -1) {
        return 0;
    }
    *str = strAlloc(read);
    if (*str == NULL) {
        return 0;
    }
    strncpy(*str, line, read - 1);
    free(line);
    return 1;
}

int main() {
    Estudante estudante;
    char *nome = NULL;
    char *endereco = NULL;
    char *matricula = NULL;
    int i;
    for (i = 0; i < 1000000; i++) {
        if (!lineReader(&nome) || !lineReader(&endereco) || !lineReader(&matricula)) {
            printf("Error reading input\n");
            return 1;
        }
        estudante.nome = nome;
        estudante.endereco = endereco;
        estudante.matricula = matricula;
        printf("%s\n", estudante.nome);
        printf("%s\n", estudante.endereco);
        printf("%s\n", estudante.matricula);
    }
    return 0;
}