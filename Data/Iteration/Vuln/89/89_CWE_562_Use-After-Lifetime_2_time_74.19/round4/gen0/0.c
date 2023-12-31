#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5;
}

void test2(int **int_pointer) {
    int i = 6;
    *int_pointer = &i;
}

int main() {
    int value = 0;
    int *pointer = &value;
    printf("Before test1: %d\n", *pointer);
    test1(pointer);
    printf("After test1: %d\n", *pointer);
    printf("Before test2: %d\n", *pointer);
    test2(&pointer);
    printf("After test2: %d\n", *pointer);
    return 0;
}