#include <stdio.h>

void test1(int *int_pointer) {
    *int_pointer = 5;
}

void test2(int **int_pointer) {
    int *i = malloc(sizeof(int));
    *i = 6;
    *int_pointer = i;
}

int main() {
    int num1 = 0;
    int *num2 = NULL;
    test1(&num1);
    test2(&num2);
    printf("num1: %d\n", num1);
    if (num2 != NULL) {
        printf("num2: %d\n", *num2);
        free(num2);
    } else {
        printf("num2 is NULL\n");
    }
    return 0;
}