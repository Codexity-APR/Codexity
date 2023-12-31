#include <stdio.h>
#include <stdlib.h>

void extend(int **v, int i) {
    int *p = realloc(*v, (i+1)*sizeof(int));
    if (p != NULL) {
        *v = p;
    } else {
        printf("Error reallocating memory!\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int *v = NULL;
    int n = 0;
    int i = 0;

    while (1) {
        if (scanf("%d", &n) == EOF) {
            break;
        }
        if (n == -1) {
            break;
        }
#ifdef DEBUG
        printf("n = %d\n", n);
#endif
        extend(&v, i);
        v[i] = n;
        i++;
    }

    for (int j = 0; j < i; j++) {
        printf("%d\n", v[j]);
    }

    free(v);
    return 0;
}