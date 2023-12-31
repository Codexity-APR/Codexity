List of vulnerabilities detected: 
Error: Buffer Overrun L2   Offset: [0, 8] (⇐ [0, 6] + [0, 2]) Size: 3.
 Example: 
   9.     for(int i = 0; i < 3; i++) {
  10.         for(int j = 0; j < 3; j++) {
  11.             printf("%d ", *(ptr + i * 3 + j));
                                ^
  12.         }
  13.         printf("\n");


#include <stdio.h>
int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *ptr = NULL;
    ptr = &matrix[0][0]; // assign the address of the first element to the pointer
    // print the elements of the matrix using pointer arithmetic
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", *(ptr + i * 3 + j));
        }
        printf("\n");
    }
    return 0;
}