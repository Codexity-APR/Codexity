#include <stdio.h>
#include <stdlib.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) {
    int i = 6;
    *int_pointer = malloc(sizeof(int)); // Allocate memory for the int pointer
    if (*int_pointer != NULL) {
        **int_pointer = i; // Assign the value of i to the dereferenced int pointer
    }
}

int main() {
    int num = 0;
    int *num_pointer = &num;
    printf("Before test1: %d\n", num);
    test1(num_pointer);
    printf("After test1: %d\n", num);
    printf("Before test2: %d\n", num);
    test2(&num_pointer);
    printf("After test2: %d\n", num);
    free(num_pointer); // Free the allocated memory
    return 0;
}