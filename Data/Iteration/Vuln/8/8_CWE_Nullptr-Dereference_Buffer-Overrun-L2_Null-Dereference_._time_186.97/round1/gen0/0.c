#include <stdio.h>
#include <stdlib.h>

int** td(int r_in, int c_in, int r_p, int c_p, int input[][c_in], int params[][c_p]) {
    int i, j, k;
    int** y_td = NULL;

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
            for (int j = 0; j < i; j++) {
                free(y_td[j]);
            }
            free(y_td);
            return NULL;
        }
    }

    // perform calculations
    for (i = 0; i < r_in; i++) {
        for (j = 0; j < c_in; j++) {
            y_td[i][j] = 0;
            for (k = 0; k < c_p; k++) {
                y_td[i][j] += input[i][k] * params[k][j];
            }
        }
    }

    return y_td;
}

int main() {
    int r_in = 3; // number of rows in input array
    int c_in = 4; // number of columns in input array
    int r_p = 4; // number of rows in params array
    int c_p = 5; // number of columns in params array

    int input[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int params[4][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    int** output = td(r_in, c_in, r_p, c_p, input, params);

    if (output != NULL) {
        // print the output
        for (int i = 0; i < r_in; i++) {
            for (int j = 0; j < c_in; j++) {
                printf("%d ", output[i][j]);
            }
            printf("\n");
        }

        // free memory
        for (int i = 0; i < r_in; i++) {
            free(output[i]);
        }
        free(output);
    }

    return 0;
}