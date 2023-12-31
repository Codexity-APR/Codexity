#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i; // Assign the address of i to the pointer to a pointer to int
}

int main() {
    int *int_pointer = NULL; // Initialize to NULL
    test2(&int_pointer);
    test1(int_pointer);
    printf("%d\n", *int_pointer); // Prints 5
    return 0;
}