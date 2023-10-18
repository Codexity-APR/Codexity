#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str) // changed function name to reverseStr and return type to char*
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added counter variable for reversed string
    
    for(i = strlen(str)-1; i >= 0; i--)
    {
        revStr[j] = str[i]; // store reversed characters in revStr
        j++; // increment counter
    }
    
    revStr[j] = '\0'; // add null terminator to mark end of reversed string
    return revStr; // return reversed string
}

int main()
{
    const char* originalStr = "Hello, World!";
    char* reversedStr = reverseStr(originalStr);
    
    printf("Original string: %s\n", originalStr);
    printf("Reversed string: %s\n", reversedStr);
    
    free(reversedStr); // free allocated memory
    
    return 0;
}