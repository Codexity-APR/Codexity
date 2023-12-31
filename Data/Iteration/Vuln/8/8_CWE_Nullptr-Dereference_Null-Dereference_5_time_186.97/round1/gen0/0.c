#include <stdio.h>
#include <stdlib.h>

int** td(int r_in, int c_in, int r_p, int c_p, int input[][c_in], int params[][c_p]) {
    int i, j, k;
    int** y_td = NULL; // Initialize y_td to NULL

    // memory allocation
    y_td = (int**)malloc(sizeof(int*) * r_in);
    if (y_td == NULL) {
        printf("Memory allocation failed for y_td\n");
        return NULL; // Return NULL if memory allocation fails
    }

    for (i = 0; i < r_in; i++) {
        y_td[i] = (int*)malloc(sizeof(int) * c_in);
        if (y_td[i] == NULL) {
            printf("Memory allocation failed for y_td[%d]\n", i);
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(y_td[j]);
            }
            free(y_td);
            return NULL; // Return NULL if memory allocation fails
        }
    }

    // performing calculations
    for (i = 0; i < r_in; i++) {
        for (j = 0; j < c_in; j++) {
            y_td[i][j] = 0;
            for (k = 0; k < c_p; k++) {
                y_td[i][j] += input[i][j] * params[j][k];
            }
        }
    }

    return y_td;
}

int main() {
    int r_in = 3; // number of rows in input array
    int c_in = 3; // number of columns in input array
    int r_p = 3; // number of rows in params array
    int c_p = 3; // number of columns in params array
    int input[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int params[3][3] = {
        {2, 0, 1},
        {1, 2, 3},
        {3, 1, 0}
    };
    int** result = td(r_in, c_in, r_p, c_p, input, params);

    if (result != NULL) {
        // printing the result
        printf("Result:\n");
        for (int i = 0; i < r_in; i++) {
            for (int j = 0; j < c_in; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }

        // freeing allocated memory
        for (int i = 0; i < r_in; i++) {
            free(result[i]);
        }
        free(result);
    }

    return 0;
}