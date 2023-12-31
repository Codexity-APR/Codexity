#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5;
}

void test2(int **int_pointer) {
    int i = 6;
    *int_pointer = &i;
}

int main() {
    int number = 0;
    int *number_pointer = &number;
    printf("Before test1: %d\n", number);
    test1(number_pointer);
    printf("After test1: %d\n", number);
    printf("Before test2: %d\n", number);
    test2(&number_pointer);
    printf("After test2: %d\n", *number_pointer);
    return 0;
}