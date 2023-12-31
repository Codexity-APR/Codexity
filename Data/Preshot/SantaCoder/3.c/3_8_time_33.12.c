#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str)
{
    if (!str) {
        return NULL;
    }

    char *revStr = malloc(strlen(str) + 1);
    if (!revStr) {
        return NULL; // Handle memory allocation error
    }

    int i;
    for(i = strlen(str)-1; i >= 0; i--) {
        revStr[strlen(str)-i-1] = str[i];
    }
    revStr[strlen(str)] = '\0';
    return revStr;
}