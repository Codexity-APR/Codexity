#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str) 
{
    if(str == NULL) return NULL; // handle NULL input string
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    if(revStr == NULL) return NULL; // check if memory allocation was successful
    int i;
    for(i = strlen(str)-1; i >= 0; i--)
        revStr[strlen(str)-1-i] = str[i];
    revStr[strlen(str)] = '\0'; // null terminate the reversed string
    return revStr;
}