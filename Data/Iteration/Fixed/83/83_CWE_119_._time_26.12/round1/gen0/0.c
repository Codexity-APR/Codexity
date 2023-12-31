#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 99 // Maximum length for the input string

int main(void)
{
    char *s = malloc(MAX_LENGTH + 1); // Allocate memory to hold a string (+1 for null terminator)
    if (s == NULL) // Check if memory allocation was successful
    {
        printf("Failed to allocate memory.");
        return 1; // Exit the program with an error code
    }
    printf("Enter a string: ");
    scanf("%99s", s); // Limit the input to 99 characters to prevent buffer overflow
    printf("The entered string is: %s\n", s);
    free(s); // Deallocate the allocated memory
    return 0;
}