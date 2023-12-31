#include <stdio.h>
#include <stdlib.h>

void add_value_to_array(int ***array, int *value_ptr) {
    *array = (int **)malloc(sizeof(int *));
    if (*array != NULL) {
        **array = value_ptr;
    }
}

int main() {
    int *arr[1] = {0};
    int value = 5;
    int *value_ptr = &value;
    add_value_to_array(&arr, value_ptr);
    printf("looool\n");
    printf("looool\n");
    printf("looool\n");
    printf("looool\n");
    free(*arr); // Free the dynamically allocated memory
    return 0;
}