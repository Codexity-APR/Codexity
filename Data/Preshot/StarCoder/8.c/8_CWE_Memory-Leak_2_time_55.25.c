#include <stdio.h>
#include <stdlib.h>

int** td(int r_in, int c_in, int r_p, int c_p, int input[][c_in], int params[][c_p]) {
    int i, j, k;
    int** y_td = NULL;

    // memory allocation
    y_td = (int**) malloc(sizeof(int*) * r_in);
    if (y_td == NULL) {
        return NULL; // memory allocation failed
    }

    for (i = 0; i < r_in; i++) {
        y_td[i] = (int*) malloc(sizeof(int) * c_p);
        if (y_td[i] == NULL) {
            // memory allocation failed, free previously allocated memory
            for (j = 0; j < i; j++) {
                free(y_td[j]);
            }
            free(y_td);
            return NULL;
        }
    }

    // compute the TD
    for (i = 0; i < r_in; i++) {
        for (j = 0; j < c_p; j++) {
            y_td[i][j] = 0;
            for (k = 0; k < c_in; k++) {
                y_td[i][j] += input[i][k] * params[k][j];
            }
        }
    }

    return y_td;
}

int main(int argc, char* argv[]) {
    int i, j;
    int r_in = 2, c_in = 3, r_p = 3, c_p = 3;
    int input[][3] = {{1, 2, 3}, {1, 2, 3}};
    int params[][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    int** y_td = NULL;

    // compute the TD
    y_td = td(r_in, c_in, r_p, c_p, input, params);
    if (y_td == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    // print the TD
    for (i = 0; i < r_in; i++) {
        for (j = 0; j < c_p; j++) {
            printf("%d ", y_td[i][j]);
        }
        printf("\n");
    }

    // free the memory
    for (i = 0; i < r_in; i++) {
        free(y_td[i]);
    }
    free(y_td);

    return 0;
}