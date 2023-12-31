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
    printf("looool\n");
    printf("looool\n");
    printf("looool\n");
    printf("looool\n");

    printf("The value stored in arr is: %d\n", **arr);
    printf("The address of value is: %p\n", value_ptr);
    printf("The address of arr is: %p\n", arr);
    printf("The address stored in arr is: %p\n", *arr);
    printf("The value stored at the address stored in arr is: %d\n", **arr);
    
    return 0;
}