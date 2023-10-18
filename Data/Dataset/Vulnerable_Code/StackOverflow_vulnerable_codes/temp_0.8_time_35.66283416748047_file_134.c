#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i; // Assign the address of i to the pointer
}

int main() {
    int x = 0;
    int *x_pointer = &x;
    
    test1(x_pointer);
    printf("Value of x after test1: %d\n", x);
    
    test2(&x_pointer);
    printf("Value of x after test2: %d\n", x);

    return 0;
}