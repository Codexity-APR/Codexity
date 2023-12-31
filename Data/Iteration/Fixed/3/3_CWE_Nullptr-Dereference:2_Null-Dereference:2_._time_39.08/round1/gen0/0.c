#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str)
{
    if (str == NULL) // Check if input string is NULL
        return NULL;

    size_t len = strlen(str);
    char* revStr = malloc(len + 1); // allocate memory for reversed string

    if (revStr == NULL) // Check if memory allocation failed
        return NULL;

    int i;
    int j = 0; // added variable to track index of reversed string

    for(i = len-1; i >= 0; i--)
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

    if (reversed != NULL) // Check if reverseStr returned a valid pointer
    {
        printf("Original string: %s\n", str);
        printf("Reversed string: %s\n", reversed);
        free(reversed); // free the allocated memory for reversed string
    }
    else
    {
        printf("Failed to reverse the string.\n");
    }

    return 0;
}