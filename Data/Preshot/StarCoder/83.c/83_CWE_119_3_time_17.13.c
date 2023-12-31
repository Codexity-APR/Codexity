#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    
    if(s == NULL) //check if allocation was successful
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter a string: ");
    scanf("%s", s); //read input string into allocated memory
    
    printf("Input string: %s\n", s);
    
    free(s); //release allocated memory
    
    return 0;
}