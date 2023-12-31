#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string

    // Check if memory allocation is successful
    if (s == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Continue with the rest of your code here...

    // Don't forget to free the allocated memory
    free(s);

    return 0;
}