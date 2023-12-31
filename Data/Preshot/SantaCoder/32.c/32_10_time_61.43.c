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
        perror("Error: Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    // Initialize the array
    for (size_t i = 0; i < size; i++) {
        array[i] = i;
    }

    // Print the array
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    // Print the array with a range
    for (size_t i = 0; i < size-1; i++) {
        printf("%ld ", inc_cp_range(&array[i], &array[i + 1]));
    }

    free(array);
    return 0;
}