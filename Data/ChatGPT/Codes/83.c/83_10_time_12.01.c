#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string

    if (s == NULL) {
        printf("Memory allocation failed");
        return 1; // return error code
    }

    // your code here

    free(s); // free the allocated memory
    return 0; // return success code
}