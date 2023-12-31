#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i; // We assign the address of i to the pointer to pointer
}

int main() {
    int *int_pointer = NULL; // Declare int_pointer and initialize it to NULL
    test1(int_pointer);
    test2(&int_pointer); // We pass a pointer to pointer to int_pointer
    printf("The value of int_pointer is %d\n", *int_pointer); // Access the value of int_pointer
    return 0;
}