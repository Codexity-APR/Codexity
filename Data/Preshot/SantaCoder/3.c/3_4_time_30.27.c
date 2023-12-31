#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str)
{
    if (str == NULL) { // handle NULL input string
        return NULL;
    }
    char* revStr = malloc(strlen(str) + 1);
    if (revStr == NULL) { // handle memory allocation failure
        return NULL;
    }
    int i;
    for(i = strlen(str)-1; i >= 0; i--) {
        revStr[strlen(str)-1-i] = str[i]; // change the order to obtain the reversed string
    }
    revStr[strlen(str)] = '\0'; // add null terminator at the end
    return revStr;
}