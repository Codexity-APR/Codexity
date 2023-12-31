#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str) // changed function name to reverseStr and return type to char*
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added variable to track index of reversed string

    for(i = strlen(str)-1; i >= 0; i--)
    {
        revStr[j] = str[i]; // assign characters in reverse order
        j++; // increment index of reversed string
    }

    revStr[j] = '\0'; // add null-terminator at the end of reversed string

    return revStr; // return reversed string
}

int main()
{
    const char *str = "Hello, World!";
    char *reversed = reverseStr(str); // call the reverseStr function

    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", reversed);

    free(reversed); // free the allocated memory for reversed string

    return 0;
}