#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    if (s == NULL) //check if memory allocation was successful
        {
            printf("Memory allocation failed\n");
            return 1;
        }
        
        printf("Enter a string: ");
        scanf("%s", s); //read input string from user
        
        printf("You entered: %s\n", s); //print the input string
        
        free(s); //free the allocated memory
        
        return 0;
    }
