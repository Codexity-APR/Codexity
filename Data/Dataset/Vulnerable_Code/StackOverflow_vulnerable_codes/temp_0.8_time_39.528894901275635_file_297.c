#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i; // Assign the address of i to the pointer to pointer
}

int main() {
    int num1 = 0;
    int *num2 = NULL;

    test1(&num1); // Pass the address of num1 to test1 function
    test2(&num2); // Pass the address of num2 to test2 function

    printf("num1: %d\n", num1); // Output: num1: 5
    printf("num2: %d\n", *num2); // Output: num2: 6

    return 0;
}