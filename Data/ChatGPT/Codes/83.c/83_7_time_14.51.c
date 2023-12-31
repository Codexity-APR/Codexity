#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string

    if (s == NULL) {
        printf("Memory allocation failed");
        return 1; //exit the program if memory allocation failed
    }

    printf("Enter a string: ");
    fgets(s, 100, stdin); //read input string from user

    printf("The entered string is: %s", s);

    free(s); //free allocated memory

    return 0;
}