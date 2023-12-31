#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str) // changed function name to reverseStr, return type to char*
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added a variable j to keep track of the index in reversed string

    for(i = strlen(str)-1; i >= 0; i--)
    {
        revStr[j] = str[i]; // store the reversed character at corresponding index in revStr
        j++; // increment j
    }

    revStr[j] = '\0'; // add null terminator to the reversed string
    return revStr;
}

int main()
{
    const char *input = "Hello, World!";
    char *reversed = reverseStr(input);
    printf("Reversed string: %s\n", reversed);
    free(reversed); // free the allocated memory
    return 0;
}