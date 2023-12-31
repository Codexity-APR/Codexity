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
        printf("Error: Failed to allocate memory\n");
        return 1;
    }
    
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
    
    // Increment elements in the array using syscall
    long result = inc_cp_range(array, array + size);
    if (result < 0) {
        printf("Error: syscall failed\n");
        free(array);
        return 1;
    }
    
    // Print the updated array
    printf("Updated Array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Free the allocated memory
    free(array);
    
    return 0;
}