#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i;
}

int main() {
    int x = 0;
    int *ptr = &x;
    printf("Before test1, x = %d\n", x);
    test1(ptr);
    printf("After test1, x = %d\n", x);
    
    int **ptr_to_ptr = &ptr;
    printf("Before test2, x = %d\n", x);
    test2(ptr_to_ptr);
    printf("After test2, x = %d\n", x);
    
    return 0;
}