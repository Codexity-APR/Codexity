#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char* str) // changed return type to char*
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0;  // added counter for reversed string index
    for (i = strlen(str) - 1; i >= 0; i--)
    {
        revStr[j] = str[i];  // assign characters in reverse order
        j++;  // increment counter
    }
    revStr[j] = '\0';  // add null-terminating character
    
    return revStr;  // return reversed string
}

int main()
{
    const char* str = "Hello, World!";
    char* reversed = reverseStr(str);
    
    printf("Original String: %s\n", str);
    printf("Reversed String: %s\n", reversed);
    
    free(reversed);  // deallocate memory
    
    return 0;
}