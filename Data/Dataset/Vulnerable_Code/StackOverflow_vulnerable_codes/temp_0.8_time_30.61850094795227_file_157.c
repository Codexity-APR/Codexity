#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i; // Assign the address of i to the double pointer
}

int main() {
    int num = 0;
    int *num_ptr = &num; // Create a pointer to int and assign the address of num to it
    
    test1(num_ptr);
    printf("Value after test1: %d\n", num); // Should print 5
    
    test2(&num_ptr);
    printf("Value after test2: %d\n", *num_ptr); // Should print 6
    
    return 0;
}