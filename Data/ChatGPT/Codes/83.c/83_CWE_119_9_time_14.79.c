#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string

    if (s == NULL)
    {
        printf("Memory allocation failed!");
        return 1; // exit the program with error code 1
    }

    printf("Enter a string: ");
    scanf("%s", s);
    printf("You entered: %s\n", s);

    free(s); // release the allocated memory

    return 0; // exit the program with success
}