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
        *(*(str)+i) = c;
        i++;
        c = getchar();
    }
    *(*(str)+i) = '\0';
    return i;
}

int main() {
    int n;
    char *str;
    Estudante *est;

    str = strAlloc(1000000);
    n = lineReader(&str);
    est = (Estudante *) malloc((n / 3) * sizeof(Estudante));

    int i = 0, j = 0;
    while (i < n) {
        est[j].nome = &str[i];
        i += strlen(&str[i]) + 1;
        est[j].endereco = &str[i];
        i += strlen(&str[i]) + 1;
        est[j].matricula = &str[i];
        i += strlen(&str[i]) + 1;
        j++;
    }

    for (i = 0; i < j; i++) {
        printf("%s %s %s\n", est[i].nome, est[i].endereco, est[i].matricula);
    }

    free(str);
    free(est);
    return 0;
}