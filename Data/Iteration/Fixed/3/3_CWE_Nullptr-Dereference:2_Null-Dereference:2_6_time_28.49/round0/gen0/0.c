#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str) // changed return type to char*
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    for(i = strlen(str)-1; i >= 0; i--)
    {
        revStr[strlen(str) - i - 1] = str[i]; // reverse the characters
    }
    revStr[strlen(str)] = '\0'; // add null terminator at the end
    return revStr; // return the reversed string
}

int main()
{
    const char *str = "Hello World!";
    char* reversed = reverStr(str);
    printf("Reversed String: %s\n", reversed);
    free(reversed); // free the allocated memory
    return 0;
}