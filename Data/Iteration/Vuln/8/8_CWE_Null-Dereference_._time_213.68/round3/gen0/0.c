#include <stdio.h>
#include <stdlib.h>

int** td(int r_in, int c_in, int r_p, int c_p, int input[][c_in], int params[][c_p]) {
    int i, j, k;
    int** y_td;

    // memory allocation
    y_td = (int**)malloc(sizeof(int*) * r_in);
    if (y_td == NULL) {
        printf("Memory allocation failed for y_td\n");
        return NULL;
    }

    for (i = 0; i < r_in; i++) {
        y_td[i] = (int*)malloc(sizeof(int) * c_in);
        if (y_td[i] == NULL) {
            printf("Memory allocation failed for y_td[%d]\n", i);

            // Free previously allocated memory
            for (j = 0; j < i; j++) {
                free(y_td[j]);
            }
            free(y_td);
            return NULL;
        }
    }

    // perform operations
    for (i = 0; i < r_in; i++) {
        for (j = 0; j < c_in; j++) {
            y_td[i][j] = 0;
            for (k = 0; k < r_p; k++) {
                y_td[i][j] += input[i][k] * params[k][j];
            }
        }
    }

    // return the result
    return y_td;
}

int main() {
    int r_in = 3;
    int c_in = 4;
    int r_p = 4;
    int c_p = 3;
    int input[r_in][c_in];
    int params[r_p][c_p];

    // populate input matrix
    printf("Enter values for input matrix:\n");
    for (int i = 0; i < r_in; i++) {
        for (int j = 0; j < c_in; j++) {
            scanf("%d", &input[i][j]);
        }
    }

    // populate parameters matrix
    printf("Enter values for parameters matrix:\n");
    for (int i = 0; i < r_p; i++) {
        for (int j = 0; j < c_p; j++) {
            scanf("%d", &params[i][j]);
        }
    }

    // perform matrix multiplication
    int** result = td(r_in, c_in, r_p, c_p, input, params);
    if (result != NULL) {
        // print result matrix
        printf("Result matrix:\n");
        for (int i = 0; i < r_in; i++) {
            for (int j = 0; j < c_p; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }

        // free memory
        for (int i = 0; i < r_in; i++) {
            free(result[i]);
        }
        free(result);
    }

    return 0;
}