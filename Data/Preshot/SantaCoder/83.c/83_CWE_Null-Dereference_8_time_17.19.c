#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string
    printf("Please enter a string: ");
    fgets(s, 100, stdin); //read user input into s
    printf("You entered: %s\n", s); //output the string
    free(s); //free the memory allocated for s
    return 0;
}