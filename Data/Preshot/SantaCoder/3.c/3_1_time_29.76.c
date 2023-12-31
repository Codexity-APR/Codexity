#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str) // changed return type to char*
{
    if (str == NULL) {
        return NULL; // handle null input string
    }
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    if (revStr == NULL) {
        return NULL; // handle memory allocation failure
    }
    int i;
    for(i = strlen(str)-1; i >= 0; i--) {
        revStr[i] = str[i];
    }
    revStr[strlen(str)] = '\0'; // add null terminator at end of reversed string
    return revStr;
}