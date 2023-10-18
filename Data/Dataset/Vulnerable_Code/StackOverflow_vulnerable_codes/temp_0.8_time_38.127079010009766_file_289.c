#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str) // changed function name to reverseStr
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added variable to keep track of the index in revStr
    
    for(i = strlen(str)-1; i >= 0; i--)
    {
        revStr[j] = str[i]; // store reversed character in revStr
        j++; // increment index in revStr
    }
    
    revStr[j] = '\0'; // add null terminator at the end of reversed string
    
    return revStr; // return the reversed string
}

int main()
{
    const char* str = "Hello, World!";
    char* reversedStr = reverseStr(str);
    
    printf("Original String: %s\n", str);
    printf("Reversed String: %s\n", reversedStr);
    
    free(reversedStr); // deallocate memory for reversed string
    
    return 0;
}