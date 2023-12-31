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
    char c = getchar();
    while (c != '\n' && c != EOF) {
        str[0][i++] = c;
        c = getchar();
    }
    str[0][i] = '\0';
    return i;
}

int main() {
    int i, j, k, n;
    char **str = NULL;
    Estudante *est = NULL;

    n = 0;
    while (lineReader(&str) > 0) {
        str = (char **) realloc(str, (n + 1) * sizeof(char *));
        str[n] = strAlloc(strlen(str[0]) + 1);
        strcpy(str[n], str[0]);
        n++;
    }

    est = (Estudante *) malloc(n * sizeof(Estudante));

    for (i = 0; i < n; i++) {
        est[i].nome = strtok(str[i], " ");
        est[i].endereco = strtok(NULL, " ");
        est[i].matricula = strtok(NULL, " ");
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