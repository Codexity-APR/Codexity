#include <stdio.h>

int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // assign the address of the first element to the pointer
    int *ptr = &matrix[0][0]; 

    // print the elements of the matrix using pointer arithmetic
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", *(ptr + (i * 3 + j)));
        }
        printf("\n");
    }

    return 0;
}