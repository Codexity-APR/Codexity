#include <stdio.h>

int main() {
    int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int (*ptr)[3] = matrix; // declare a pointer to a pointer and point it to the first element of the matrix
    
    // Accessing elements of the matrix using pointers
    printf("%d\n", **ptr); // prints 1
    printf("%d\n", *(*ptr + 1)); // prints 2
    printf("%d\n", **(ptr + 1)); // prints 4
    
    printf("%d\n", *(*(ptr+1) + 1)); // prints 5
    printf("%d\n", *(*ptr + 2)); // prints 3
    printf("%d\n", *(*(ptr+2))); // prints 7
    printf("%d\n", *(*(ptr+2) + 2)); // prints 9

    return 0;
}