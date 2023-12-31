#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5; 
}

void test2(int **int_pointer) { // We need to pass a pointer to a pointer to int
    int i = 6;
    *int_pointer = &i;
}

int main() {
    int i = 0;
    int *int_pointer = &i;
    test1(int_pointer);
    printf("%d\n", *int_pointer);
    test2(&int_pointer);
    printf("%d\n", *int_pointer);
    return 0;
}