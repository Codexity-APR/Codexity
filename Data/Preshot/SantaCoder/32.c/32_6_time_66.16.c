#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>

#define __NR_inc_cp_range 286

long inc_cp_range(void *start_addr, void *end_addr) {
    return syscall(__NR_inc_cp_range, start_addr, end_addr);
}

int main(int argc, char *argv[]) {
    size_t size = 1024;
    int *array = malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Error: memory allocation failed\n");
        return 1;
    }

    // Initialize the array
    for (size_t i = 0; i < size; i++) {
        array[i] = (int)i;
    }

    // Print the original array
    printf("Original array:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Print the array with range
    printf("Array with range:\n");
    for (size_t i = 0; i < size - 1; i++) {
        printf("%ld ", inc_cp_range(&array[i], &array[i + 1]));
    }

    free(array);
    return 0;
}