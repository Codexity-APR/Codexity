#include <stdio.h>
#include <stdlib.h>

void extend(int **v, int i) {
    int *p = realloc(*v, (i+1)*sizeof(int));
    if (p != NULL) {
        *v = p;
    } else {
        printf("Error reallocating memory!\n");
        exit(1); // Exit the program if realloc fails
    }
}

int main() {
    int *v = malloc(sizeof(int));
    int n = 0;
    int i = 0;
    
    if (v == NULL) {
        printf("Error allocating memory!\n");
        return 1; // Exit the program if malloc fails
    }

    while (n != -1) {
        scanf("%d", &n);
        if (n != -1) {
            extend(&v, i);
            v[i] = n;
            i++;
        }
    }

    for (int j = 0; j < i; j++) {
        printf("%d ", v[j]);
    }

    free(v);
    return 0;
}