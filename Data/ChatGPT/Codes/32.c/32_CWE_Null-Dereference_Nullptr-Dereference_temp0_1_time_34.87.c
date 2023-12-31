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

    // Print the array before incrementing
    printf("Array before incrementing:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Increment the array using the inc_cp_range system call
    long result = inc_cp_range(array, array + size);

    // Check if the system call was successful
    if (result < 0) {
        perror("inc_cp_range");
        return 1;
    }

    // Print the array after incrementing
    printf("Array after incrementing:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}