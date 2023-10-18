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
        array[i] = i + 1;
    }
    
    // Print the initial array
    printf("Initial Array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Call the system call to increment the array elements
    long result = inc_cp_range(array, array + size);
    if (result == 0) {
        printf("Array elements incremented successfully!\n");
    } else {
        printf("Failed to increment array elements!\n");
    }

    // Print the modified array
    printf("Modified Array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);
    
    return 0;
}