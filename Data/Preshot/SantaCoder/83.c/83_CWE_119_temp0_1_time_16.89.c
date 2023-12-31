#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    printf("Enter a string: ");
    scanf("%s", s); //read a string from the user and store it in s
    printf("You entered: %s\n", s); //print the string to the screen
    free(s); //free the string
    return 0;
}