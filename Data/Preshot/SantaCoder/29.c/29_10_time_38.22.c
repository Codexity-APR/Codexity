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

    printf("Value of value_ptr: %d\n", *value_ptr);
    printf("Value of the element in arr: %d\n\n", **arr);

    **arr = 10;

    printf("Value of value_ptr: %d\n", *value_ptr);
    printf("Value of the element in arr after modification: %d\n", **arr);
    
    return 0;
}