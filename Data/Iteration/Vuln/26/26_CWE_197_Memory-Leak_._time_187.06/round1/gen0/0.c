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
    int c; // Changed the type to int to handle EOF correctly
    *str = strAlloc(1);
    if (*str == NULL) {
        return 0;
    }
    while ((c = getchar()) != '\n' && c != EOF) {
        (*str)[i++] = (char) c;
        *str = realloc(*str, (i+1) * sizeof(char));
        if (*str == NULL) {
            return 0;
        }
    }
    (*str)[i] = '\0';
    return 1;
}

int main() {
    Estudante estudante;
    printf("Nome: ");
    if (lineReader(&estudante.nome)) {
        printf("Endereco: ");
        if (lineReader(&estudante.endereco)) {
            printf("Matricula: ");
            if (lineReader(&estudante.matricula)) {
                printf("\nDados do Estudante:\n");
                printf("Nome: %s\n", estudante.nome);
                printf("Endereco: %s\n", estudante.endereco);
                printf("Matricula: %s\n", estudante.matricula);
                free(estudante.nome);
                free(estudante.endereco);
                free(estudante.matricula);
                return 0;
            }
            free(estudante.endereco);
        }
        free(estudante.nome);
    }
    printf("Erro ao ler entrada.\n");
    return 1;
}