#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i; // Assign the address of i to the pointer to pointer
}

int main() {
    int num = 0;
    int *num_ptr = &num;

    test1(num_ptr);
    printf("After test1: %d\n", num); // Output: 5

    test2(&num_ptr);
    printf("After test2: %d\n", *num_ptr); // Output: 6

    return 0;
}