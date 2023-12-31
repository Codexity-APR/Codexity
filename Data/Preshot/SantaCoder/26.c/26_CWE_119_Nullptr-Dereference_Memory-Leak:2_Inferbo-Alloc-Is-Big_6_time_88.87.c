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
    while (c != '\n') {
        str[0][i++] = c;
        c = getchar();
    }
    str[0][i] = '\0';
    return i;
}

int main() {
    int n, i, j, num;
    char *str = strAlloc(1000000);
    n = lineReader(&str);

    Estudante *est = (Estudante *) malloc(n * sizeof(Estudante));
    num = 0;

    for (i = 0; i < n; i++) {
        if (str[i] == ' ') {
            num++;
        }
    }
    num = num / 3;

    j = 0;
    for (i = 0; i < num; i++) {
        est[i].nome = (char *) malloc(50 * sizeof(char));
        est[i].endereco = (char *) malloc(100 * sizeof(char));
        est[i].matricula = (char *) malloc(10 * sizeof(char));

        sscanf(&str[j], "%s %s %s", est[i].nome, est[i].endereco, est[i].matricula);
        j += strlen(est[i].nome) + strlen(est[i].endereco) + strlen(est[i].matricula) + 3;
    }
    
    for (i = 0; i < num; i++) {
        printf("%s %s %s\n", est[i].nome, est[i].endereco, est[i].matricula);
    }

    return 0;
}