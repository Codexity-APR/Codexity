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
        perror("Error allocating memory: ");
        return 1;
    }
    
    // Initialize the array
    for (size_t i = 0; i < size; i++) {
        array[i] = i;
    }
    
    // Display the array before incrementing
    printf("Array before incrementing:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Call the syscall to increment the array
    long result = inc_cp_range(array, array + size);
    if (result < 0) {
        perror("Error incrementing array: ");
        return 1;
    }
    
    // Display the array after incrementing
    printf("Array after incrementing:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Free the allocated memory
    free(array);
    
    return 0;
}