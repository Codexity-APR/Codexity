#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str) // changed return type to char*
{
    if(str == NULL) {
        return NULL;
    }
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    if(revStr == NULL) {
        return NULL;
    }
    int i;
    for(i = strlen(str)-1; i >= 0; i--) {
        revStr[i] = str[i];
    }
    revStr[i+1] = '\0';
    return revStr;
}

int main()
{
    const char* str = "Hello World!";
    printf("The original string is: %s\n", str);
    char* revStr = reverStr(str);
    if(revStr == NULL) {
        printf("Failed to allocate memory for reversed string.");
        return 1;
    }
    printf("The reversed string is: %s\n", revStr);
    free(revStr);
    return 0;
}