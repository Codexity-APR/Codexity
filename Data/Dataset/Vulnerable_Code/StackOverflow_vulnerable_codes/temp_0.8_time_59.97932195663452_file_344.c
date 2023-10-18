#include <stdio.h>
#include <stdlib.h>

int** td (int r_in, int c_in, int r_p, int c_p, int input[][c_in], int params[][c_p]){
    int i, j, k;
    int** y_td;

    // memory allocation
    y_td = (int**)malloc(sizeof(int*)*r_in);
    for (i=0; i < r_in; i++){
        y_td[i] = (int*)malloc(sizeof(int)*c_in);
    }

    // computation
    for (i=0; i < r_in; i++){
        for (j=0; j < c_in; j++){
            y_td[i][j] = 0;
            for (k=0; k < c_p; k++){
                y_td[i][j] += input[i][j] * params[i][k];
            }
        }
    }

    return y_td;
}

int main() {
    int r_in = 2;
    int c_in = 2;
    int r_p = 2;
    int c_p = 2;

    int input[2][2] = {{1, 2}, {3, 4}};
    int params[2][2] = {{2, 1}, {1, 3}};

    int** result = td(r_in, c_in, r_p, c_p, input, params);

    // print the result matrix
    printf("Result:\n");
    for (int i=0; i < r_in; i++){
        for (int j=0; j < c_in; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (int i=0; i < r_in; i++){
        free(result[i]);
    }
    free(result);

    return 0;
}