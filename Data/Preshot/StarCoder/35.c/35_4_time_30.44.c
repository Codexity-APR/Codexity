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
    int *v = NULL; // Initialize to NULL
    int n = 0;
    int i = 0;

    while (1) { // Use an infinite loop
        if (scanf("%d", &n) != 1) { // Check if input is valid
            printf("Invalid input. Exiting...\n");
            exit(1);
        }
        if (n == -1) {
            break; // Exit loop
        }
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