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
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1) {        
        str[i] = strAlloc(len);
        strcpy(str[i], line);
        i++;
    }

    return i;
}

int main() {
    int i, n;
    char **str;
    Estudante *est;

    str = (char **) malloc(1000000 * sizeof(char *));
    n = lineReader(str);

    est = (Estudante *) malloc(n * sizeof(Estudante));

    for (i = 0; i < n; i++) {
        char *token;
        token = strtok(str[i], " ");
        est[i].nome = token;
        token = strtok(NULL, " ");
        est[i].endereco = token;
        token = strtok(NULL, " ");
        est[i].matricula = token;
    }

    for (i = 0; i < n; i++) {
        printf("%s %s %s", est[i].nome, est[i].endereco, est[i].matricula);
    }

    return 0;
}