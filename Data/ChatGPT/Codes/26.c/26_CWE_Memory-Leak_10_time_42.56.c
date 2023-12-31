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
    int c, i = 0;
    *str = strAlloc(1);
    
    if (*str == NULL) {
        printf("Memory allocation error!");
        return 0;
    }
    
    while ((c = getchar()) != '\n' && c != EOF) {
        (*str)[i++] = c;
        *str = realloc(*str, (i + 1) * sizeof(char));
        
        if (*str == NULL) {
            printf("Memory allocation error!");
            return 0;
        }
    }
    
    (*str)[i] = '\0';
    return 1;
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
    
    free(estudante.nome);
    free(estudante.endereco);
    free(estudante.matricula);
    
    return 0;
}