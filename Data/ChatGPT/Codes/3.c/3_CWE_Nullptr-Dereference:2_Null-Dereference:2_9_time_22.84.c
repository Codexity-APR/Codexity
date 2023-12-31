#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str)
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added index variable for reversed string
    
    for (i = strlen(str)-1; i >= 0; i--)
    {
        revStr[j] = str[i]; // store reversed characters in revStr
        j++; // increment index for reversed string
    }
    
    revStr[j] = '\0'; // add null terminator to the end of reversed string
    
    return revStr; // return the reversed string
}

int main()
{
    const char* str = "Hello, World!";
    char* reversedStr = reverseStr(str);
    
    printf("Reversed string: %s\n", reversedStr);
    
    free(reversedStr); // free the allocated memory
    
    return 0;
}