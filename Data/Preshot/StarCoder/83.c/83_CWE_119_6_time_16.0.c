#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); // allocate memory to hold a string
    if (s == NULL) // check if memory allocation failed
    {
        printf("Memory allocation failed\n");
        return 1; // return with error code
    }

    printf("Enter a string: ");
    scanf("%s", s); // read input string

    printf("The string you entered is: %s\n", s);

    free(s); // free the allocated memory
    
    return 0;
}