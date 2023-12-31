List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 18 by call to `strAlloc()`, is not freed after the last access at line 27, column 17.
 Example: 
  25.             capacity *= 2;
  26.             char *newLine = realloc(line, capacity * sizeof(char));
  27.             if (newLine == NULL) {
                      ^
  28.                 free(line);
  29.                 return -1;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *nome;
    char *endereco;
    char *matricula;
} Estudante;
char *strAlloc(int n) {
    return (char *) malloc((n + 1) * sizeof(char));
}
int lineReader(char **str) {
    int size = 0;
    int capacity = 1;
    char *line = strAlloc(capacity);
    if (line == NULL) {
        return -1;
    }
    int c = getchar();
    while (c != '\n' && c != EOF) {
        if (size + 1 >= capacity) {
            capacity *= 2;
            char *newLine = realloc(line, capacity * sizeof(char));
            if (newLine == NULL) {
                free(line);
                return -1;
            }
            line = newLine;
        }
        line[size++] = (char) c;
        c = getchar();
    }
    line[size] = '\0';
    *str = line;
    return size;
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