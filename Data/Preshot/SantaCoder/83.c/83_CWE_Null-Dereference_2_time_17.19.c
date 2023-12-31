#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    printf("Enter a string: "); //ask user to input a string
    fgets(s, 100, stdin); //get the string from the user
    printf("You entered: %s", s); //print the string to the screen
    free(s); //free the string
    return 0;
}