#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str) // changed return type to char*
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added variable to keep track of position in the reversed string

    for(i = strlen(str)-1; i >= 0; i--)
    {
        revStr[j] = str[i]; // assign character from original string to reversed string
        j++; // increment position in reversed string
    }

    revStr[j] = '\0'; // add null terminator to the reversed string

    return revStr; // return the reversed string
}

int main() {
    const char* original = "Hello, World!";
    char* reversed = reverStr(original);

    printf("Original String: %s\n", original);
    printf("Reversed String: %s\n", reversed);

    free(reversed); // free the dynamically allocated memory

    return 0;
}