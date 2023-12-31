#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string

    if (s == NULL) //check if allocation was successful
    {
        printf("Memory allocation failed!");
        return 1;
    }

    printf("Enter a string: ");
    fgets(s, 100, stdin); // read string from user input

    printf("The string you entered is: %s", s);

    free(s); // release memory allocated to s

    return 0;
}