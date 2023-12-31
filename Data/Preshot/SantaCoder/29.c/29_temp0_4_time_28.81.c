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
    printf("Value: %d\n", **arr); // prints "Value: 5"
    **arr = 10; // changes the value of "value" to 10
    printf("Value: %d\n", *value_ptr); // prints "Value: 10"
    return 0;
}