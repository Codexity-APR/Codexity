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
    char buffer[1000];
    while (fgets(buffer, 1000, stdin) != NULL) {
        str[i] = strAlloc(strlen(buffer) + 1);
        strcpy(str[i], buffer);
        i++;
    }
    return i;
}

int main() {
    int i, n;
    char **str;
    Estudante *est;

    str = (char **) malloc(1000 * sizeof(char *));
    n = lineReader(str);
    est = (Estudante *) malloc(n * sizeof(Estudante));

    for (i = 0; i < n; i++) {
        est[i].nome = strtok(str[i], " \n");
        est[i].endereco = strtok(NULL, " \n");
        est[i].matricula = strtok(NULL, " \n");
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