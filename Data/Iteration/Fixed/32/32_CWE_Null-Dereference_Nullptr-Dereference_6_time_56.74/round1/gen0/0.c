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
        printf("Error: Failed to allocate memory\n");
        return 1;
    }
    
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
    
    // Increment the array using the system call
    long result = inc_cp_range(array, array + size);
    
    // Check if the system call was successful
    if (result == 0) {
        // Print the array after incrementing
        printf("Array after incrementing:\n");
        for (size_t i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    } else {
        printf("Error: Failed to increment array\n");
    }
    
    // Free the allocated memory
    free(array);
    
    return 0;
}