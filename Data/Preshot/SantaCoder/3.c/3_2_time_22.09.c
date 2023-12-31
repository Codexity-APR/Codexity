#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str) // changed return type to char*
{
    if(str == NULL) return NULL; // null check
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    if(revStr == NULL) return NULL; // null check
    int i;
    for(i = strlen(str)-1; i >= 0; i--)
        revStr[strlen(str) - i - 1] = str[i]; // copy string in reverse order
    revStr[strlen(str)] = '\0'; // add null terminator
    return revStr;
}