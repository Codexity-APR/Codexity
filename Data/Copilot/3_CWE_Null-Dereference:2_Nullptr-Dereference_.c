#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str) // changed return type to char*
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    for(i = strlen(str)-1; i >= 0; i--)
    {
        revStr[strlen(str)-1-i] = str[i]; // reverse the string
    }
    revStr[strlen(str)] = '\0'; // add null terminator at the end of the reversed string
    return revStr; // return the reversed string
    }
