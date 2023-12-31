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

    // code to complete
    for (i = 0; i < r_in; i++) {
        for (j = 0; j < c_in; j++) {
            y_td[i][j] = input[i][j];
        }
    }

    return y_td;
}

int main() {
    // example usage
    int input[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int params[2][2] = {
        {10, 11},
        {12, 13}
    };

    int** result = td(3, 3, 2, 2, input, params);

    // printing the result
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // deallocating memory
    for (int i = 0; i < 3; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}