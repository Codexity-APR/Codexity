#include <stdio.h>
#include <stdlib.h>

int** td (int r_in, int c_in, int r_p, int c_p, int input[][c_in], int params[][c_p]){
    int i, j, k;
    int** y_td = NULL;

    // memory allocation
    y_td = (int**)malloc(sizeof(int*)*r_in);
    if (y_td == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
	
    for (i=0; i < r_in; i++){
        y_td[i] = (int*)malloc(sizeof(int)*c_in);
        if (y_td[i] == NULL) {
            printf("Memory allocation failed!\n");
            return NULL;
        }
    }

    // compute the TD
    for (i=0; i < r_in; i++){
        for (j=0; j < c_in; j++){
            y_td[i][j] = 0;
            for (k=0; k < c_p; k++){
                y_td[i][j] += input[i][j] * params[k][j];
            }
        }
    }

    return y_td;
}

int main(int argc, char* argv[]){
    int i, j, k;
    int r_in = 2, c_in = 3, r_p = 3, c_p = 3;
    int input[r_in][c_in];
    int params[r_p][c_p];
    int** y_td = NULL;

    // read input
    for (i=0; i < r_in; i++){
        for (j=0; j < c_in; j++){
            input[i][j] = i*j;
        }
    }

    // read params
    for (i=0; i < r_p; i++){
        for (j=0; j < c_p; j++){
            params[i][j] = i*j;
        }
    }

    // compute the TD
    y_td = td(r_in, c_in, r_p, c_p, input, params);

    if (y_td != NULL) {
        // print the TD
        for (i=0; i < r_in; i++){
            for (j=0; j < c_in; j++){
                printf("%d ", y_td[i][j]);
            }
            printf("\n");
        }

        // free memory
        for (i=0; i < r_in; i++){
            free(y_td[i]);
        }
        free(y_td);
    }

    return 0;
}