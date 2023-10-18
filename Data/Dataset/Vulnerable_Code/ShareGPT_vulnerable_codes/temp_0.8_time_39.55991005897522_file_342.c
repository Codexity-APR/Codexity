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

    // Initialize the array
    for (size_t i = 0; i < size; i++) {
        array[i] = i;
    }

    // Increment and copy the array
    int *new_array = malloc(size * sizeof(int));
    if (new_array == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    memcpy(new_array, array, size * sizeof(int));

    // Print the copied array
    printf("Copied array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", new_array[i]);
    }
    printf("\n");

    free(array);
    free(new_array);

    return 0;
}