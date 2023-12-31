#include <stdio.h>
#include <stdlib.h>

void extend(int **v, int i) {
    int *p = realloc(*v, (i+1)*sizeof(int));
    if (p != NULL) {
        *v = p;
    } else {
        printf("Error reallocating memory!\n");
        exit(1);
    }
}

int main() {
    int *v = malloc(sizeof(int));
    if (!v) {
        printf("Error allocating memory!\n");
        return 1;
    }
    int n = 0;
    int i = 0;

    while (n != -1) {
        if (scanf("%d", &n) != 1) {
            printf("Invalid input!\n");
            free(v);
            return 1;
        }
        if (n != -1) {
#ifdef DEBUG
            printf("n = %d\n", n);
#endif
            extend(&v, i);
            v[i++] = n;
        }
    }

    for (int j = 0; j < i; j++) {
        printf("%d\n", v[j]);
    }

    free(v);
    return 0;
}