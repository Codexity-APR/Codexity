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
    int *v = malloc(sizeof(int));
    if (v == NULL) {
        printf("Error allocating memory!\n");
        exit(EXIT_FAILURE);
    }
    int n = 0;
    int i = 0;

    while (1) {
        if (scanf("%d", &n) != 1) {
            printf("Error reading input!\n");
            exit(EXIT_FAILURE);
        }
        if (n == -1) {
            break;
        }
        i++;
        extend(&v, i);
        v[i-1] = n;
    }

    // print out the array
    for (int j = 0; j < i; j++) {
        printf("%d ", v[j]);
    }
    printf("\n");

    free(v);
    return 0;
}