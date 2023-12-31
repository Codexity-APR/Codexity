#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string

    if (s == NULL) //check if memory allocation was successful
    {
        printf("Failed to allocate memory.");
        return 1; //exit the program with an error code
    }

    printf("Enter a string: ");
    scanf("%s", s);

    printf("The entered string is: %s\n", s);

    free(s); //deallocate the allocated memory

    return 0;
}