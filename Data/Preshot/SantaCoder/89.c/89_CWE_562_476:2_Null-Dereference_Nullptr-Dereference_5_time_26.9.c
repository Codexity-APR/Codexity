#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i;
}

int main() {
    int *int_pointer = NULL; // Assigning NULL to pointer
    test1(int_pointer);
    test2(&int_pointer); // Passing address of pointer to pointer
    printf("%d", *int_pointer); // Dereferencing pointer to get the value
    return 0;
}