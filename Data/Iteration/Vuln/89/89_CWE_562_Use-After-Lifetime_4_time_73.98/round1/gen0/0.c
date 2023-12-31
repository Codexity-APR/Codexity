#include <stdio.h>
#include <stdlib.h>

void test1(int *int_pointer) {
    *int_pointer = 5;
}

void test2(int **int_pointer) {
    int *i = malloc(sizeof(int));
    *i = 6;
    *int_pointer = i;
}

int main() {
    int *num_pointer = malloc(sizeof(int));
    *num_pointer = 0;

    printf("Before test1: %d\n", *num_pointer);
    test1(num_pointer);
    printf("After test1: %d\n", *num_pointer);
    printf("Before test2: %d\n", *num_pointer);
    test2(&num_pointer);
    printf("After test2: %d\n", *num_pointer);

    free(num_pointer); // Free the dynamically allocated memory
    return 0;
}