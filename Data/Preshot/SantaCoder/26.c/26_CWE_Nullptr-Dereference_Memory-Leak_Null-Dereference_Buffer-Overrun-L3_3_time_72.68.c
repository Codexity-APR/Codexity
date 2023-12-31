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
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        str[n] = strAlloc(strlen(buffer) + 1);
        strcpy(str[n], buffer);
        n++;
    }
    return n;
}

int main() {
    int i;
    int n;
    char *str[1000];
    Estudante *est;

    n = lineReader(str);
    est = (Estudante *) malloc(n * sizeof(Estudante));

    for (i = 0; i < n; i++) {
        est[i].nome = strtok(str[i], " ");
        est[i].endereco = strtok(NULL, " ");
        est[i].matricula = strtok(NULL, " \n"); 
    }

    for (i = 0; i < n; i++) {
        printf("%s %s %s\n", est[i].nome, est[i].endereco, est[i].matricula);
    }

    return 0;
}