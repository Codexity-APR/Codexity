#include <stdio.h>
#include <stdlib.h>

int** td(int r_in, int c_in, int r_p, int c_p, int input[][c_in], int params[][c_p]) {
    int i, j, k;
    int** y_td = NULL;

    y_td = (int**)malloc(sizeof(int*) * r_in);
    if (y_td == NULL) {
        printf("Memory allocation failed for y_td\n");
        return NULL;
    }

    for (i = 0; i < r_in; i++) {
        y_td[i] = (int*)malloc(sizeof(int) * c_in);
        if (y_td[i] == NULL) {
            printf("Memory allocation failed for y_td[%d]\n", i);

            for (j = 0; j < i; j++) {
                free(y_td[j]);
            }
            free(y_td);
            return NULL;
        }
    }

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
    int r_in = 3;
    int c_in = 3;
    int r_p = 3;
    int c_p = 3;
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
        printf("Result:\n");
        for (int i = 0; i < r_in; i++) {
            for (int j = 0; j < c_in; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < r_in; i++) {
            free(result[i]);
        }
        free(result);
    }

    return 0;
}