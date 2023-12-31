#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str) // changed return type to char*
{
    if (str == NULL) {
        return NULL;
    }
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    if (revStr == NULL) {
        return NULL;
    }
    int i;
    for(i = strlen(str)-1; i >= 0; i--) {
        revStr[strlen(str)-1-i] = str[i];
    }
    revStr[strlen(str)] = '\0';
    return revStr;
}