#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 99 // Maximum length of the input string

int main(void)
{
    char *s = malloc(MAX_LENGTH + 1); // Allocate memory to hold a string (+1 for null terminator)
    if (s == NULL)
    {
        printf("Memory allocation failed!");
        return 1; // Exit the program with error code 1
    }
    printf("Enter a string: ");
    scanf("%99s", s); // Limit the input to 99 characters to prevent buffer overflow
    printf("You entered: %s\n", s);
    free(s); // Release the allocated memory
    return 0; // Exit the program with success
}