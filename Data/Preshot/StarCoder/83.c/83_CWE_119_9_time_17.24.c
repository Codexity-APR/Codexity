#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string

    if (s == NULL) //check if memory allocation was successful
    {
        printf("Memory allocation failed.");
        return 1;
    }

    printf("Please enter a string: ");
    scanf("%s", s);

    printf("The string you entered is: %s\n", s);

    free(s); //deallocate the memory

    return 0;
}