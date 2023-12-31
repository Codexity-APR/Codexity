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
    do {
        str[i] = strAlloc(100);
        fgets(str[i], 100, stdin);
        str[i][strlen(str[i]) - 1] = '\0';
        i++;
    } while (strcmp(str[i - 1], "0") != 0 && strcmp(str[i - 1], "0\n") != 0); // reads lines until 0 is entered
    return i - 1;
}

int main() {
    int n, i;
    char **str = (char **) malloc(sizeof(char *) * 100);
    Estudante *est = (Estudante *) malloc(sizeof(Estudante) * 100);

    n = lineReader(str);

    for (i = 0; i < n; i++) {
        est[i].nome = str[i];
        est[i].endereco = str[i + 1];
        est[i].matricula = str[i + 2];
        i += 2;
    }

    for (i = 0; i < n; i++) {
        printf("%s %s %s\n", est[i].nome, est[i].endereco, est[i].matricula);
    }

    for (i = 0; i < n; i++) {
        free(str[i]);
    }
    free(str);
    free(est);

    return 0;
}