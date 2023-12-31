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
    char ch;
    *str = strAlloc(1000000);
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            (*str)[i++] = '\0';
            break;
        }
        (*str)[i++] = ch;
    }
    return i;
}

int main() {
    int i, n;
    char *str;
    Estudante *est;

    n = lineReader(&str);
    est = (Estudante*) malloc(n / 3 * sizeof(Estudante));

    for (i = 0; i < n; i += 3) {
        est[i / 3].nome = str + i;
        est[i / 3].endereco = str + i + 1;
        est[i / 3].matricula = str + i + 2;
    }

    for (i = 0; i < n / 3; i++) {
        printf("%s %s %s\n", est[i].nome, est[i].endereco, est[i].matricula);
    }

    free(est);
    free(str);

    return 0;
}