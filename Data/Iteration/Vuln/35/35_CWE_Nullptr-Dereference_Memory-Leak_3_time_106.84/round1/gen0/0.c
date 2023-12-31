#include <stdio.h>
#include <stdlib.h>

void extend(int **v, int i) {
    int *p = realloc(*v, (i+1)*sizeof(int));
    if (p != NULL) {
        *v = p;
    } else {
        printf("Error reallocating memory!\n");
        exit(1); // Exit the program if memory reallocation fails
    }
}

int main() {
    int *v = malloc(sizeof(int));
    if (v == NULL) {
        printf("Error allocating memory!\n");
        return 1; // Exit the program if memory allocation fails
    }
    int n = 0;
    int i = 0;
    while (n != -1) {
        scanf("%d", &n);
        if (n != -1) {
            extend(&v, i);
            v[i] = n;
            i++;
        }
    }
    printf("Final array: ");
    for (int j = 0; j < i; j++) {
        printf("%d ", v[j]);
    }
    printf("\n");
    free(v);
    return 0;
}