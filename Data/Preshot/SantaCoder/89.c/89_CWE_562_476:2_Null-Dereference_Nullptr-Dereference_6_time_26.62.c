#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i; // Set the value of the pointer to the address of i
}

int main() {
    int *int_pointer = NULL;
    test1(int_pointer);
    test2(&int_pointer);
    printf("%d\n", *int_pointer); // Should print 6
    return 0;
}