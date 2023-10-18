#include <stdio.h>
#include <stdlib.h>

int** td (int r_in, int c_in, int r_p, int c_p, int input[][c_in], int params[][c_p]) {
    int i, j, k;
    int** y_td;

    // Memory allocation
    y_td = (int**)malloc(sizeof(int*) * r_in);
    for (i = 0; i < r_in; i++) {
        y_td[i] = (int*)malloc(sizeof(int) * c_in);
    }

    // Perform calculations
    for (i = 0; i < r_in; i++) {
        for (j = 0; j < c_in; j++) {
            y_td[i][j] = 0;

            // Apply transformation
            for (k = 0; k < r_p; k++) {
                y_td[i][j] += params[k][0] * input[i + params[k][1]][j + params[k][2]];
            }
        }
    }

    return y_td;
}

int main() {
    // Test input and parameters
    int r_in = 3;
    int c_in = 3;
    int input[][3] = {{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}};
    int r_p = 2;
    int c_p = 3;
    int params[][3] = {{1, -1, 0},
                       {2, 1, 1}};

    // Compute transformed array
    int** transformed = td(r_in, c_in, r_p, c_p, input, params);

    // Print transformed array
    printf("Transformed Array:\n");
    for (int i = 0; i < r_in; i++) {
        for (int j = 0; j < c_in; j++) {
            printf("%d ", transformed[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < r_in; i++) {
        free(transformed[i]);
    }
    free(transformed);

    return 0;
}