#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i; // We assign the address of i to the pointer to pointer
}

int main() {
    int *p;
    int i = 0;
    p = &i;
    printf("Value of i before: %d\n", i);
    test1(p); // Pass the address of i to the function test1
    printf("Value of i after test1: %d\n", i);
    test2(&p); // Pass the address of the pointer to i to the function test2
    printf("Value of i after test2: %d\n", *p);
}