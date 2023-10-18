#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str) // changed return type to char*
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added a counter variable
    
    for(i = strlen(str)-1; i >= 0; i--)
    {
        revStr[j] = str[i]; // store reversed characters in revStr
        j++; // increment counter
    }
    revStr[j] = '\0'; // terminate the string
    
    return revStr; // return the reversed string
}

int main()
{
    const char* originalStr = "Hello, World!";
    char* reversedStr = reverStr(originalStr);
    
    printf("Original string: %s\n", originalStr);
    printf("Reversed string: %s\n", reversedStr);
    
    free(reversedStr); // free the allocated memory
    
    return 0;
}