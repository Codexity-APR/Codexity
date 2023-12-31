#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    
    // check if allocation was successful
    if (s == NULL) {
        printf("Error: memory allocation failed!\n");
        return 1;
    }
    
    // get input string from user
    printf("Enter a string: ");
    scanf("%s", s);
    
    // print the input string
    printf("You entered: %s\n", s);
    
    // free the allocated memory
    free(s);
    
    return 0;
}