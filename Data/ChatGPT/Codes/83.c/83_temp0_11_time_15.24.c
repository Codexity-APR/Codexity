#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); //allocate memory to hold a string

    if (s == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter a string: ");
    fgets(s, 100, stdin); // read input string from user

    printf("You entered: %s\n", s);

    free(s); // free the allocated memory

    return 0;
}