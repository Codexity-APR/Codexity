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

    // code implementation
    for (i = 0; i < r_in; i++) {
        for (j = 0; j < c_in; j++) {
            // perform calculations here
            // example: y_td[i][j] = input[i][j] + params[i][j];
        }
    }

    return y_td;
}

int main() {
    int input[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int params[3][3] = { {1, 1, 1}, {2, 2, 2}, {3, 3, 3} };
    int** result = td(3, 3, 3, 3, input, params);

    // print the result
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (int i = 0; i < 3; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}