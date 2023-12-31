#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5;
}

void test2(int **int_pointer) {
    int i = 6;
    *int_pointer = &i;
}

int main() {
    int x = 0;
    int *ptr = &x;
    test1(ptr);
    printf("After test1, x = %d\n", x);
    
    int y = 0; // Declare a new variable y
    int *ptr2 = &y; // Assign the address of y to ptr2
    test2(&ptr2);
    printf("After test2, x = %d\n", x);
    
    return 0;
}