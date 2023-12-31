#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); // Allocate memory to hold a string

    // Check if memory allocation was successful
    if (s == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1; // Exit the program with an error
    }

    // Code to perform operations on the string 's' can be added here

    free(s); // Deallocate the memory

    return 0; // Exit the program successfully
}