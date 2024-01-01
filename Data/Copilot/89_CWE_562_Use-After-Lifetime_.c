#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i; // Assign the address of i to the pointer to pointer
    }

    int main() {
        int x = 0;
        int *p = &x;
        printf("Before test1: %d\n", x);
        test1(p);
        printf("After test1: %d\n", x);
        printf("Before test2: %d\n", *p);
        test2(&p);
        printf("After test2: %d\n", *p);
        return 0;
    }
