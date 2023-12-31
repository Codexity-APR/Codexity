#include <stdio.h>
#include <stdlib.h>

int** td (int r_in, int c_in, int r_p, int c_p, int input[][c_in], int params[][c_p]){
    int i, j, k;
    int** y_td;

    // memory allocation
    y_td = (int**)malloc(sizeof(int*)*r_in);
    if (y_td == NULL){
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }
    for (i=0; i < r_in; i++){
        y_td[i] = (int*)malloc(sizeof(int)*c_in);
        if (y_td[i] == NULL){
            printf("Error: Memory allocation failed.\n");
            return NULL;
        }
    }

    // initialize
    for (i=0; i < r_in; i++){
        for (j=0; j < c_in; j++){
            y_td[i][j] = input[i][j];
        }
    }

    // main loop
    for (i=0; i < r_in; i++){
        for (j=0; j < c_in; j++){
            if (y_td[i][j] == 0){
                for (k=0; k < c_p; k++){
                    y_td[i][j] += params[j][k];
                }
            }
        }
    }

    return y_td;
}