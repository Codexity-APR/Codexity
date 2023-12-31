#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str)
{
    if(str == NULL) return NULL;
    size_t len = strlen(str);
    char* revStr = malloc(len + 1); // allocate memory for reversed string
    if(revStr == NULL) return NULL;
    int i;
    for(i = len-1; i >= 0; i--)
        revStr[len-i-1] = str[i];
    revStr[len] = '\0';
    return revStr;
}

int main(void)
{
    const char* str = "Hello World!";
    printf("The original string is: %s\n", str);
    char* revStr = reverseStr(str);
    if(revStr != NULL) {
        printf("The reversed string is: %s\n", revStr);
        free(revStr);
        revStr = NULL;
    }
    else {
        printf("Failed to allocate memory for reversed string\n");
    }
    return 0;
}