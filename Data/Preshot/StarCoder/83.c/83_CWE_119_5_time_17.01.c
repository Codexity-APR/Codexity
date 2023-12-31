#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    
    if (s == NULL) //check if memory allocation was successful
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter a string: ");
    scanf("%s", s); //read a string from user input
    
    printf("The string you entered is: %s\n", s); //print the string
    
    free(s); //free the memory allocated for the string
    
    return 0;
}