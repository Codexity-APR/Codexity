#include <stdio.h>
#include <stdlib.h>

int** td(int r_in, int c_in, int r_p, int c_p, int input[][c_in], int params[][c_p]){
    int i, j, k;
    int** y_td;

    // memory allocation
    y_td = (int**)malloc(sizeof(int*) * r_in);
    for (i = 0; i < r_in; i++){
        y_td[i] = (int*)malloc(sizeof(int) * c_in);
    }

    // perform transformations
    for (i = 0; i < r_in; i++){
        for (j = 0; j < c_in; j++){
            y_td[i][j] = 0;
            for (k = 0; k < c_p; k++){
                y_td[i][j] += input[i][params[i][k]];
            }
        }
    }

    return y_td;
}

int main(){
    // define input and params arrays
    int input[3][4] = {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12}};
    int params[3][2] = {{0, 2},
                        {1, 3},
                        {0, 3}};

    // compute transformed array
    int r_in = 3;
    int c_in = 4;
    int r_p = 3;
    int c_p = 2;
    int** result = td(r_in, c_in, r_p, c_p, input, params);

    // display transformed array
    printf("Transformed Array:\n");
    for (int i = 0; i < r_in; i++){
        for (int j = 0; j < c_in; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (int i = 0; i < r_in; i++){
        free(result[i]);
    }
    free(result);

    return 0;
}