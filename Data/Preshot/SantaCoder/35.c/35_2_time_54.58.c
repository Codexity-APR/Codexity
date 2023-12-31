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

    while (n != -1) {
        int ret = scanf("%d", &n);
        if (ret != 1) {
            printf("Invalid input!\n");
            exit(1);
        }
        if (n != -1) {
            i++;
            extend(&v, i);
            v[i-1] = n;
        }
    }

    // free memory before exit
    free(v);
    return 0;
}