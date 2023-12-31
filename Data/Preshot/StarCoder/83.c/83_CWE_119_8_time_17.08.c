#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    
    if (s == NULL) //check if memory allocation was successful
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter a string: ");
    scanf("%s", s); //read a string from user input and store it in the allocated memory
    
    printf("The string entered is: %s\n", s); //print the entered string
    
    free(s); //free the allocated memory
    
    return 0;
}