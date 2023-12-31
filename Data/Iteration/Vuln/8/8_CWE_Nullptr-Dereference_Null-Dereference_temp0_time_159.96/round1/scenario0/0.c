List of vulnerabilities detected: 
Error: Memory Leak   Pulse found a potential memory leak. Memory dynamically allocated at line 16 by call to `malloc`, is not freed after the last access at line 23, column 13.
 Example: 
  21.                 free(y_td[j]);
  22.             }
  23.             free(y_td);
                  ^
  24.             return NULL;
  25.         }


#include <stdio.h>
#include <stdlib.h>
int** td(int r_in, int c_in, int r_p, int c_p, int input[][c_in], int params[][c_p]) {
    int i, j;
    int** y_td = NULL; // Initialize to NULL
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
            for (j = 0; j < i; j++) {
                free(y_td[j]);
            }
            free(y_td);
            return NULL;
        }
    }
    // code to complete
    return y_td;
}
int main() {
    // example usage
    int r_in = 3;
    int c_in = 3;
    int r_p = 2;
    int c_p = 2;
    int input[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int params[2][2] = {
        {1, 2},
        {3, 4}
    };
    int** result = td(r_in, c_in, r_p, c_p, input, params);
    if (result != NULL) {
        // print the result
        for (int i = 0; i < r_in; i++) {
            for (int j = 0; j < c_in; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        // free memory
        for (int i = 0; i < r_in; i++) {
            free(result[i]);
        }
        free(result);
    }
    return 0;
}