#include <stdio.h>
#include <stdlib.h>

void extend(int **v, int i) {
    int *p = realloc(*v, (i+1)*sizeof(int));
    if (p == NULL) {
        printf("Error reallocating memory!\n");
        exit(1);
    } else {
        *v = p;
    }
}

int main() {
    int *v = NULL;
    int n = 0;
    int i = 0;

    while (1) {
        if (scanf("%d", &n) != 1 || n == -1) {
            break;
        }
#ifdef __cplusplus
        i++;
#endif
        extend(&v, i);
        v[i-1] = n;
    }

    free(v);
    return 0;
}