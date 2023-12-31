#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); // allocate memory to hold a string
    printf("Please enter a string: ");
    scanf("%s", s); // read string input from user

    printf("You entered: %s\n", s); // display the entered string

    free(s); // free the allocated memory

    return 0;
}