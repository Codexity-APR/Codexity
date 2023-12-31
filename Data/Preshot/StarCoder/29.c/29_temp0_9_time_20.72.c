#include <stdio.h>
#include <stdlib.h>

void add_value_to_array(int ***array, int *value_ptr) {
    *array = &value_ptr;
}

int main() {
    int *arr[1] = {0}; // or int **arr = malloc(sizeof(int *));
    int value = 5;
    int *value_ptr = &value;

    add_value_to_array(&arr, value_ptr);
    // arr = &value_ptr;
    printf("Value of arr[0]: %d\n", **arr);
    printf("Value of value_ptr: %d\n", *value_ptr);
    printf("Value of *arr[0]: %d\n", *arr[0]);
    printf("Value of &value_ptr: %p\n", (void*)&value_ptr);
    printf("Value of *arr: %p\n", (void*)*arr);
    printf("Value of **arr: %d\n", **arr);
    return 0;
} 

This code defines a function `add_value_to_array` that takes a pointer to a pointer to a pointer to an integer (`int ***array`) and a pointer to an integer (`int *value_ptr`). The function sets the value of the pointer to a pointer to a pointer to an integer (`***array`) to the address of the pointer to an integer (`&value_ptr`).

In the `main` function, an array of pointers to integers `arr` is defined and initialized to `{0}