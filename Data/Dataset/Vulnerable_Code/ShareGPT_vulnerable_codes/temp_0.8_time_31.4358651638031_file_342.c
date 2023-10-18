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

    // Print the array
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Call the syscall
    long result = inc_cp_range(array, array + size - 1);

    // Check if the syscall was successful
    if (result == 0) {
        printf("inc_cp_range completed successfully\n");
    } else {
        printf("inc_cp_range failed with error code %ld\n", result);
    }

    // Free the memory
    free(array);

    return 0;
}