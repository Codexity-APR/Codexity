#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str) // changed function name from reverStr to reverseStr and return type to char*
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added counter variable to keep track of index in reversed string
    for (i = strlen(str) - 1; i >= 0; i--)
    {
        revStr[j] = str[i]; // store character in reverse order
        j++; // increment counter
    }
    revStr[j] = '\0'; // add null character at the end to terminate the string
    return revStr; // return the reversed string
}

int main()
{
    const char* str = "Hello, world!";
    char* reversed = reverseStr(str);
    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", reversed);
    free(reversed); // free the allocated memory
    return 0;
}