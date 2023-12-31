#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str)
{
    if (str == NULL) { // Check if the input string is NULL
        return NULL;
    }
    size_t len = strlen(str);
    char* revStr = malloc(len + 1); // allocate memory for reversed string
    if (revStr == NULL) { // Check if memory allocation was successful
        return NULL;
    }
    int i;
    for(i = len-1; i >= 0; i--)
        revStr[len-1-i] = str[i];
    revStr[len] = '\0'; // terminate the reversed string with NULL character
    return revStr;
}