#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str)
{
    if (!str) {
        return NULL;
    }

    size_t len = strlen(str);
    char* revStr = malloc(len + 1);

    if (!revStr) {
        return NULL;
    }

    int i;
    for (i = len - 1; i >= 0; i--) {
        revStr[len - i - 1] = str[i];
    }

    revStr[len] = '\0';
    return revStr;
}