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

    // code to fill y_td array
    for (i = 0; i < r_in; i++) {
        for (j = 0; j < c_in; j++) {
            // code to calculate y_td[i][j]
            y_td[i][j] = 0;
            for (k = 0; k < c_p; k++) {
                y_td[i][j] += input[i][k] * params[k][j];
            }
        }
    }

    return y_td;
}

int main() {
    int r_in = 3, c_in = 4; // example values, change as per your requirements
    int r_p = 4, c_p = 2;   // example values, change as per your requirements

    int input[][4] = {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12}};

    int params[][2] = {{1, 2},
                       {3, 4},
                       {5, 6},
                       {7, 8}};

    int** result = td(r_in, c_in, r_p, c_p, input, params);

    // code to print the result
    printf("Result:\n");
    for (int i = 0; i < r_in; i++) {
        for (int j = 0; j < c_in; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // memory deallocation
    for (int i = 0; i < r_in; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}