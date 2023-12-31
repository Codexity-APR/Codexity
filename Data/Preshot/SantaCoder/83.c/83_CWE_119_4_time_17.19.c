#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    printf("Enter a string: ");
    scanf("%s", s); //read a string from the user and store it in s
    printf("The string you entered is: %s", s); //print the string to the screen
    free(s); //free the memory allocated for s
    return 0;
}