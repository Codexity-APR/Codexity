#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    printf("Please enter a string: ");
    fgets(s, 100, stdin); //read a string from the user
    printf("You entered: %s", s); //print the string to the screen
    free(s); //free the string
    return 0;
}