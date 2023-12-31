#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    printf("Please enter a string: ");
    scanf("%s", s); //read user input string into s
    printf("You entered: %s\n", s); //print the entered string to the screen
    free(s); //free the string
    return 0;
}