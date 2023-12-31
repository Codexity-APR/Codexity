#include <stdio.h>
#include <stdlib.h>

void add_value_to_array(int ***array, int *value_ptr) {
    *array = malloc(sizeof(int **));
    **array = value_ptr;
}

int main() {
    int **arr = malloc(sizeof(int *));
    int value = 5;
    int *value_ptr = &value;

    add_value_to_array(&arr, value_ptr);

    printf("looool\n");
    printf("looool\n");
    printf("looool\n");
    printf("looool\n");

    free(arr);

    return 0;
}