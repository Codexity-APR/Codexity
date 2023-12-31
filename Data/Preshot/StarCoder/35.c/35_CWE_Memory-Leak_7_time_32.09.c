#include <stdio.h>
#include <stdlib.h>

void extend(int **v, int i) {
    int *p = realloc(*v, (i+1)*sizeof(int));
    if (p == NULL) { // Check if realloc fails
        printf("Error reallocating memory!\n");
        exit(1); // Terminate the program if realloc fails
    }
    *v = p;
}

int main() {
    int *v = malloc(sizeof(int));
    if (v == NULL) { // Check if malloc fails
        printf("Error allocating memory!\n");
        exit(1); // Terminate the program if malloc fails
    }
    int n = 0;
    int i = 0;

    while (n != -1) {
        if (scanf("%d", &n) != 1) { // Check if input is valid
            printf("Invalid input!\n");
            exit(1); // Terminate the program if input is invalid
        }
        if (n != -1) {
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