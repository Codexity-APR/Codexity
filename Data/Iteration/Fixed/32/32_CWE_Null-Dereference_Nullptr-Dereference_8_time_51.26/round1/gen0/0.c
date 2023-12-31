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
    
    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }
    
    // Initialize the array
    for (size_t i = 0; i < size; i++) {
        array[i] = i;
    }
    
    // Print the original array
    printf("Original Array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Increment the values in the array using inc_cp_range system call
    long result = inc_cp_range(array, array + size);
    
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