#include <stdio.h>
#include <stdlib.h>

void extend(int **v, int i) {
    int *p = realloc(*v, (i+1)*sizeof(int));
    if (p != NULL) {
        *v = p;
    } else {
        printf("Error reallocating memory!\n");
        exit(1); // terminate the program in case of error
    }
}

int main() {
    int *v = NULL;
    int n = 0;
    int i = 0;

    while (n != -1) {
        if (scanf("%d", &n) != 1) {
            printf("Invalid input!\n");
            exit(1); // terminate the program in case of invalid input
        }
        if (n != -1) {
            i++;
            int *v_temp = realloc(v, i * sizeof(int));
            if (v_temp == NULL) {
                printf("Error reallocating memory!\n");
                exit(1);
            }
            v = v_temp;
            v[i-1] = n;
        }
    }

    // free the allocated memory
    free(v);
    v = NULL;

    return 0;
}