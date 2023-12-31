#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str) // changed function name to reverseStr, return type to char*
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added a counter variable
    
    for(i = strlen(str)-1; i >= 0; i--)
    {
        revStr[j] = str[i]; // store the reversed characters in revStr
        j++;
    }
    
    revStr[j] = '\0'; // add null terminator to indicate end of reversed string
    
    return revStr; // return the reversed string
}

int main()
{
    const char* str = "Hello, World!";
    char* reversed = reverseStr(str);
    
    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", reversed);
    
    free(reversed); // free the allocated memory
    
    return 0;
}