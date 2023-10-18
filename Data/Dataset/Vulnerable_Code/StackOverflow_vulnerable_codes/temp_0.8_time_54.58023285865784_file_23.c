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
    while ((c = getchar()) != '\n') {
        (*str)[i++] = c;
        *str = realloc(*str, (i + 1) * sizeof(char));
    }
    (*str)[i] = '\0';
    return i;
}

int main() {
    Estudante estudante;
    
    printf("Nome: ");
    estudante.nome = strAlloc(1);
    lineReader(&(estudante.nome));
    
    printf("Endereço: ");
    estudante.endereco = strAlloc(1);
    lineReader(&(estudante.endereco));
    
    printf("Matrícula: ");
    estudante.matricula = strAlloc(1);
    lineReader(&(estudante.matricula));
    
    printf("\nDados do estudante:\n");
    printf("Nome: %s\n", estudante.nome);
    printf("Endereço: %s\n", estudante.endereco);
    printf("Matrícula: %s\n", estudante.matricula);
    
    free(estudante.nome);
    free(estudante.endereco);
    free(estudante.matricula);
    
    return 0;
}