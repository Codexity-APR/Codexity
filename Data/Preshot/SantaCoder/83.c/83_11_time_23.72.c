#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    if (s == NULL) {
        printf("Memory allocation failed!\n");
        return 1; //Exit the program with an error
    }
    printf("Enter a string: ");
    fgets(s, 100, stdin); //Read a string from the user
    printf("You entered: %s", s);
    free(s); //free the memory allocated for the string
    return 0; //Exit the program
}