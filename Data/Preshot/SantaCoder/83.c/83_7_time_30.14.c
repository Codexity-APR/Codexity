#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    if(s == NULL){ //check if memory allocation was successful
        printf("Memory allocation failed"); //print error message
        return 1; //exit program with error code
    }
    
    printf("Enter a string: "); //prompt user to enter a string
    fgets(s, 100, stdin); //read input from user
    
    printf("You entered: %s", s); //print the entered string
    
    free(s); //free the allocated memory
    
    return 0;
}