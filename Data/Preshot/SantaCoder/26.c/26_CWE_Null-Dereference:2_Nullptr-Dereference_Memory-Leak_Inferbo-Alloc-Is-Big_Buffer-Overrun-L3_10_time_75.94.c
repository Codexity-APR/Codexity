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
    char buffer[1000];
    int i = 0;
    while(fgets(buffer, 1000, stdin) != NULL) {
        str[i] = strAlloc(strlen(buffer) + 1);
        strcpy(str[i], buffer);
        i++;
    }
    return i;
}

int main() {
    int i;
    int n;
    char **str;
    Estudante *est;

    str = (char**)strAlloc(1000000);
    n = lineReader(str);
    est = (Estudante*)strAlloc(n * sizeof(Estudante));

    for (i = 0; i < n; i++) {
        est[i].nome = str[i];
        est[i].endereco = str[i + 1];
        est[i].matricula = str[i + 2];
        i += 2;
    }

    for (i = 0; i < n; i++) {
        printf("%s%s%s\n", est[i].nome, est[i].endereco, est[i].matricula);
    }

    return 0;
}