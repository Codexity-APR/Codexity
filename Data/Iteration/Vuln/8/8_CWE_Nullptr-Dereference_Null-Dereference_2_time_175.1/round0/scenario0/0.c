List of vulnerabilities detected: 
Error: Nullptr Dereference   Pulse found a potential null pointer dereference  on line 9 indirectly during the call to `td()`in call to `td()` .
 Example: 
  39.                        {0, 2, -1}};
  40. 
  41.     int** result = td(r_in, c_in, r_p, c_p, input, params);
                         ^
  42. 
  43.     // Print the result

Error: Null Dereference   pointer `y_td` last assigned on line 9 could be null and is dereferenced at line 11, column 9.
 Example: 
   9.     y_td = (int**)malloc(sizeof(int*)*r_in);
  10.     for (i=0; i < r_in; i++){
  11.         y_td[i] = (int*)malloc(sizeof(int)*c_in);
              ^
  12.     }
  13.


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
    // Perform calculations
    for(i = 0; i < r_in; i++){
        for(j = 0; j < c_in; j++){
            y_td[i][j] = 0;
            for(k = 0; k < r_p; k++){
                y_td[i][j] += input[i][k] * params[k][j];
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
    int input[][3] = {{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}};
    int params[][3] = {{2, 0, 1},
                       {1, -1, 2},
                       {0, 2, -1}};
    int** result = td(r_in, c_in, r_p, c_p, input, params);
    // Print the result
    printf("Result:\n");
    for(int i = 0; i < r_in; i++){
        for(int j = 0; j < c_in; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    // Free memory
    for(int i = 0; i < r_in; i++){
        free(result[i]);
    }
    free(result);
    return 0;
}