#include <stdio.h>
#include <stdlib.h>

void extend(int **v, int i) {
    int *p = realloc(*v, (i+1)*sizeof(int));
    if (p != NULL) {
        *v = p;
    } else {
        printf("Error reallocating memory!\n");
    }
}

int main() {
    int *v = malloc(sizeof(int));
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

    printf("The numbers entered are: ");
    for (int j = 0; j < i; j++) {
        printf("%d ", v[j]);
    }
    printf("\n");

    free(v);

    return 0;
}