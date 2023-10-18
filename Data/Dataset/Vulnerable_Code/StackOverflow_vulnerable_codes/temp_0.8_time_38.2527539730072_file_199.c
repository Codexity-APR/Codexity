#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char* str)
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added variable for reversed string index
    for (i = strlen(str) - 1; i >= 0; i--)
    {
        revStr[j] = str[i]; // store the characters in reverse order
        j++; // increment the index of reversed string
    }
    revStr[j] = '\0'; // add null terminator at the end of reversed string
    return revStr; // return the reversed string
}

int main()
{
    const char* str = "Hello, World!";
    char* reversed = reverseStr(str);
    printf("Reversed string: %s\n", reversed);
    free(reversed); // don't forget to free the allocated memory
    return 0;
}