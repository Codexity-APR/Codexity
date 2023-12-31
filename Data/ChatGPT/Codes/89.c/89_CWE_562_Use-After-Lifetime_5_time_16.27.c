#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i;
}

int main() {
    int num = 0;
    int *num_pointer = &num;

    test1(num_pointer);
    printf("Value after test1: %d\n", num);

    test2(&num_pointer);
    printf("Value after test2: %d\n", *num_pointer);

    return 0;
}