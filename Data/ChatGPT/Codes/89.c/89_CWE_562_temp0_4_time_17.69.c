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
    int *num_pointer = &num;

    printf("Before test1: %d\n", num);
    test1(num_pointer);
    printf("After test1: %d\n", num);

    printf("Before test2: %d\n", num);
    test2(&num_pointer);
    printf("After test2: %d\n", num);

    return 0;
}