#include <stdio.h>
#include <stdlib.h>

void extend(int **v, int i) {
    int *p = realloc(*v, (i+1)*sizeof(int));
    if (p != NULL) {
        *v = p;
    } else {
        printf("Error reallocating memory!\n");
        exit(EXIT_FAILURE); // added to terminate the program if realloc fails
    }
}

int main() {
    int *v = NULL; // initialized to NULL
    int n = 0;
    int i = 0;

    while (true) { // infinite loop
        scanf("%d", &n);
        if (n == -1) {
            break; // break the loop if n is -1
        }
        i++;
        extend(&v, i);
        v[i-1] = n; // store the value of n in the i-th element of v
    }
    
    // print the elements of v
    for (int j = 0; j < i; j++) {
        printf("%d ", v[j]);
    }
    printf("\n");

    free(v); // free the allocated memory
    return 0;
}