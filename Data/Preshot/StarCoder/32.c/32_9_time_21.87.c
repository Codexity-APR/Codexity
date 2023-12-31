#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 1024;
    int *array = malloc(size * sizeof(int));
    
    if (array == NULL) {
        printf("Error: Failed to allocate memory\n");
        return 1;
    }

    // Initialize the array
    for (size_t i = 0; i < size; i++) {
        array[i] = i;
    }

    // Print the array
    for (size_t i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }

    // Free the array
    free(array);
    array = NULL;
    
    return 0;
}