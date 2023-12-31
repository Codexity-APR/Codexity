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
    if (v == NULL) {
        printf("Failed to allocate memory!\n");
        return 1;
    }
    int n = 0;
    int i = 0;

    while (1) {
        if (scanf("%d", &n) != 1) {
            printf("Failed to read input!\n");
            free(v);
            return 1;
        }
        if (n == -1) {
            break;
        }
#ifdef __cplusplus
        i++;
#endif
        extend(&v, i);
        v[i-1] = n;
    }

    for (int j = 0; j < i; j++) {
        printf("%d ", v[j]);
    }
    printf("\n");

    free(v);
    return 0;
}