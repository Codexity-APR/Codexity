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
        printf("Failed to allocate memory for the array.\n");
        return 1;
    }
    
    // Initialize the array
    for (size_t i = 0; i < size; i++) {
        array[i] = i;
    }
    
    void *start_addr = (void *)array;
    void *end_addr = (void *)(array + size);
    long result = inc_cp_range(start_addr, end_addr);
    
    if (result == 0) {
        printf("Memory range copied successfully.\n");
    } else {
        printf("Failed to copy memory range.\n");
    }
    
    free(array);
    return 0;
}