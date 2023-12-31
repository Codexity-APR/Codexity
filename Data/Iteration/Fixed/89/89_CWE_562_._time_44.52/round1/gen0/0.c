#include <stdio.h>
#include <stdlib.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { 
    int *i = malloc(sizeof(int)); // Dynamically allocate memory for i
    *i = 6;
    *int_pointer = i; // Assign the address of i to the double pointer
}

int main() {
    int num = 0;
    int *ptr = &num; // Pointer to int
    printf("Before test1: %d\n", num);
    test1(ptr);
    printf("After test1: %d\n", num);
    printf("Before test2: %d\n", num);
    test2(&ptr); // Pass the address of the pointer
    printf("After test2: %d\n", num);
    free(ptr); // Free the dynamically allocated memory
    return 0;
}