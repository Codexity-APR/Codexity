#include <stdio.h>
#include <stdlib.h>

void test1(int *int_pointer) {
    if (int_pointer != NULL) {
        *int_pointer = 5;
    }
}

void test2(int **int_pointer) {
    int *i = malloc(sizeof(int));
    if (i != NULL) {
        *i = 6;
        *int_pointer = i;
    }
}

int main() {
    int num = 0;
    int *ptr = &num;
    test1(ptr);
    printf("After test1: %d\n", num);
    int *temp_ptr = NULL;
    test2(&temp_ptr);
    if (temp_ptr != NULL) {
        int temp = *temp_ptr;
        printf("After test2: %d\n", temp);
        free(temp_ptr);
    }
    return 0;
}