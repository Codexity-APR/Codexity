#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    
    if (s == NULL) //check if memory allocation was successful
    {
        printf("Memory allocation failed!");
        return 1; //exit the program with a non-zero value to indicate failure
    }
    
    printf("Enter a string: ");
    fgets(s, 100, stdin); //read a string from the user
    
    printf("You entered: %s\n", s); //print the entered string
    
    free(s); //free the allocated memory
    
    return 0; //exit the program successfully
}