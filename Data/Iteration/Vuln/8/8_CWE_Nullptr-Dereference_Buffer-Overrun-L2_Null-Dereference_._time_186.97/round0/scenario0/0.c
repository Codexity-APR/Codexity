List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 9 indirectly during the call to `td()`in call to `td()` .
 Example: 
  44.     };
  45. 
  46.     int** output = td(r_in, c_in, r_p, c_p, input, params);
                         ^
  47. 
  48.     // print the output

Error: Buffer Overrun L2   Offset: [0, 4] Size: 4 by call to `td`.
 Example: 
  44.     };
  45. 
  46.     int** output = td(r_in, c_in, r_p, c_p, input, params);
                         ^
  47. 
  48.     // print the output

Error: Null Dereference   pointer `y_td` last assigned on line 9 could be null and is dereferenced at line 11, column 9.
 Example: 
   9.     y_td = (int**)malloc(sizeof(int*) * r_in);
  10.     for (i = 0; i < r_in; i++) {
  11.         y_td[i] = (int*)malloc(sizeof(int) * c_in);
              ^
  12.     }
  13.


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
    // perform calculations
    for (i = 0; i < r_in; i++) {
        for (j = 0; j < c_in; j++) {
            y_td[i][j] = 0;
            for (k = 0; k < c_p; k++) {
                y_td[i][j] += input[i][k] * params[k][j];
            }
        }
    }
    return y_td;
}
int main() {
    int r_in = 3; // number of rows in input array
    int c_in = 4; // number of columns in input array
    int r_p = 4; // number of rows in params array
    int c_p = 5; // number of columns in params array
    int input[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int params[4][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
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