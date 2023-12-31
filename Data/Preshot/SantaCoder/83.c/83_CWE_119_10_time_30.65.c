#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    if(s == NULL) //check if memory allocation was successful
    {
        printf("Memory allocation failed");
        return 1;
    }
    
    printf("Please enter a string: ");
    scanf("%s", s); //read input string from user
    
    printf("The entered string is: %s", s); //print the input string to the screen
    
    free(s); //free the allocated memory
    return 0;
}