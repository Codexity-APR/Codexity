#include <stdio.h>
#include <stdlib.h>

int** td(int r_in, int c_in, int r_p, int c_p, int input[][c_in], int params[][c_p]) {
    int i, j, k;
    int** y_td;

    // memory allocation
    y_td = (int**)malloc(sizeof(int*) * r_in);
    for (i = 0; i < r_in; i++) {
        y_td[i] = (int*)malloc(sizeof(int) * c_in);
    }

    // computation
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
    int r_in = 3; // number of rows in input
    int c_in = 3; // number of columns in input
    int r_p = 3; // number of rows in params
    int c_p = 2; // number of columns in params

    int input[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int params[3][2] = {
        {2, 3},
        {4, 5},
        {6, 7}
    };

    int** output = td(r_in, c_in, r_p, c_p, input, params);

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

    return 0;
}