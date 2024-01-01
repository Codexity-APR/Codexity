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
    while ((c = getchar()) != '\n' && c != EOF) {
        *str = (char *) realloc(*str, (n + 1) * sizeof(char));
        (*str)[n++] = c;
    }
    *str = (char *) realloc(*str, (n + 1) * sizeof(char));
    (*str)[n] = '\0';
    return n;
}

int main() {
    Estudante estudante;
    printf("Digite o nome do estudante: ");
    estudante.nome = strAlloc(1);
    lineReader(&estudante.nome);
    printf("Digite o endereco do estudante: ");
    estudante.endereco = strAlloc(1);
    lineReader(&estudante.endereco);
    printf("Digite a matricula do estudante: ");
    estudante.matricula = strAlloc(1);
    lineReader(&estudante.matricula);
    printf("Nome: %s\nEndereco: %s\nMatricula: %s\n", estudante.nome, estudante.endereco, estudante.matricula);
    free(estudante.nome);
    free(estudante.endereco);
    free(estudante.matricula);
    return 0;
}
