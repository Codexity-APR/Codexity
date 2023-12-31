#include <stdio.h>

int main() {
    int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int (*ptr)[3] = matrix; // declare a pointer to a pointer and point it to the first element of the matrix
    
    // Accessing elements of the matrix using pointers
    printf("%d\n", **ptr); // prints 1
    printf("%d\n", *(*ptr + 1)); // prints 2
    printf("%d\n", **(ptr + 1)); // prints 4
    
    // Changing the values of the matrix using pointers
    **ptr = 10;
    printf("%d\n", matrix[0][0]); // prints 10
    
    *(*ptr + 1) = 20;
    printf("%d\n", matrix[0][1]); // prints 20
    
    **(ptr + 1) = 30;
    printf("%d\n", matrix[1][0]); // prints 30
    
    return 0;
}