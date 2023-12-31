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
        if (c == EOF) {
            return -1;
        }
        if (c == '\r') {
            continue;
        }
        str[0][i] = c;
        i++;
    }
    str[0][i] = '\0';
    return i;
}

int main() {
    int i;
    int n;
    char *str;
    Estudante *est;

    printf("Digite o número de estudantes: ");
    scanf("%d", &n);
    getchar(); // to consume the newline character

    est = (Estudante *) malloc(n * sizeof(Estudante));
    for (i = 0; i < n; i++) {
        est[i].nome = strAlloc(100);
        est[i].endereco = strAlloc(100);
        est[i].matricula = strAlloc(10);

        printf("Digite o nome do estudante %d: ", (i + 1));
        lineReader(&est[i].nome);
        printf("Digite o endereço do estudante %d: ", (i + 1));
        lineReader(&est[i].endereco);
        printf("Digite a matrícula do estudante %d: ", (i + 1));
        lineReader(&est[i].matricula);
    }

    printf("Dados dos estudantes:\n");
    for (i = 0; i < n; i++) {
        printf("Nome: %s\nEndereço: %s\nMatrícula: %s\n\n", est[i].nome, est[i].endereco, est[i].matricula);
        free(est[i].nome);
        free(est[i].endereco);
        free(est[i].matricula);
    }
    free(est);

    return 0;
}