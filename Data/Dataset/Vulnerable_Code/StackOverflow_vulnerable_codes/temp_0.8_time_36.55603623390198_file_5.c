#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) {
    int i = 6;
    *int_pointer = &i; // Assign the address of i to int_pointer
}

int main() {
    int num1 = 0;
    int *num2 = NULL;

    test1(&num1);
    printf("num1: %d\n", num1); // Output: num1: 5

    test2(&num2);
    printf("num2: %d\n", *num2); // Output: num2: 6

    return 0;
}