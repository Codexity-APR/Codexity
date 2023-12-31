#include <stdio.h>
#include <stdlib.h>

void test1(int *int_pointer) {
    *int_pointer = 5;
}

void test2(int **int_pointer) {
    int *i = malloc(sizeof(int)); // Allocate memory for i

    if (i != NULL) {
        *i = 6;
        *int_pointer = i;
    } else {
        // Handle memory allocation failure
        // You can choose to exit the program or take appropriate action
        printf("Memory allocation failed\n");
        exit(1);
    }
}

int main() {
    int x = 0;
    int *ptr = &x;

    test1(ptr);
    printf("After test1, x = %d\n", x);

    int y = 0;
    int *ptr2 = &y;

    test2(&ptr2);
    printf("After test2, x = %d\n", x);

    free(ptr2); // Free the dynamically allocated memory

    return 0;
}