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

    // print the value stored in the array
    printf("%d\n", **arr);

    // change the value of the original variable
    value = 10;

    // print the updated value stored in the array
    printf("%d\n", **arr);

    // change the value of the variable through the pointer in the array
    **arr = 15;

    // print the updated value of the original variable
    printf("%d\n", value);

    return 0;
}