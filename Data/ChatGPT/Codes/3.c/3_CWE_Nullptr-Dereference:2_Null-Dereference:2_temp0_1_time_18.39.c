#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str) // changed function name to reverseStr and return type to char*
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added a counter variable to keep track of the reversed string index
    for(i = strlen(str)-1; i >= 0; i--)
    {
        revStr[j] = str[i]; // store the characters in reverse order
        j++; // increment the counter
    }
    revStr[j] = '\0'; // add null terminator at the end of the reversed string
    return revStr; // return the reversed string
}

int main()
{
    const char* str = "Hello, World!";
    char* reversed = reverseStr(str);
    printf("Reversed String: %s\n", reversed);
    free(reversed); // free the dynamically allocated memory
    return 0;
}