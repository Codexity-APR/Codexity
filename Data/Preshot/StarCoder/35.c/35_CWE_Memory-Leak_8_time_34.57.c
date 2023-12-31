#include <stdio.h>
#include <stdlib.h>

void extend(int **v, int i) {
    int *p = realloc(*v, (i+1)*sizeof(int));
    if (p == NULL) {
        printf("Error reallocating memory!\n");
        exit(EXIT_FAILURE);
    }
    *v = p;
}

int main() {
    int *v = malloc(sizeof(int));
    if (v == NULL) {
        printf("Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }
    int n = 0;
    int i = 0;

    while (n != -1) {
        if (scanf("%d", &n) != 1) {
            printf("Invalid input!\n");
            exit(EXIT_FAILURE);
        }
        if (n != -1) {
#ifdef DEBUG
            printf("n = %d\n", n);
#endif
            extend(&v, i);
            v[i] = n;
            i++;
        }
    }

    for (int j = 0; j < i; j++) {
        printf("%d\n", v[j]);
    }

    free(v);
    return 0;
}