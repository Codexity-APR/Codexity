#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i; // assign the address of i to the pointer to a pointer to an int
}

int main() {
    int i = 0;
    test1(&i);
    printf("%d\n", i);
    test2(&i);
    printf("%d\n", *i);
}