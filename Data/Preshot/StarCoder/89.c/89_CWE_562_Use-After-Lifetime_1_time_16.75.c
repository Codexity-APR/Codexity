#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i; // Set the value of the pointer to the address of i
}

int main() {
    int i = 0;
    test1(&i);
    printf("%d\n", i);

    int *p = NULL; // Declare a pointer to int
    test2(&p); // Pass the address of the pointer to the function
    printf("%d\n", *p); // Dereference the pointer to access the value of i

    return 0;
}