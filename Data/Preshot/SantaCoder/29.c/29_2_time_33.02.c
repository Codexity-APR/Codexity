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

    // print the value using the array
    printf("Value = %d\n", **arr); // should print "Value = 5"

    // free the array if it was allocated dynamically
    // free(arr);

    return 0;
}