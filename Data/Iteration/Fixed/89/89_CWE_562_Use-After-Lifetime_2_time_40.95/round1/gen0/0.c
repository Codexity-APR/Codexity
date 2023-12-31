#include <stdio.h>
#include <stdlib.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) {
    int *i = malloc(sizeof(int)); // Allocate memory for an integer
    *i = 6;
    *int_pointer = i; // Assign the address of the dynamically allocated integer to the pointer to pointer
}

int main() {
    int num = 0;
    int *ptr = &num;
    test1(ptr);
    printf("Value after test1: %d\n", num);
    test2(&ptr);
    printf("Value after test2: %d\n", *ptr);
    free(ptr); // Free the dynamically allocated memory
    return 0;
}