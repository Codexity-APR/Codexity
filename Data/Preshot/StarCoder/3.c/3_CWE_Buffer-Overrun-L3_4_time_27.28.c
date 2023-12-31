#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverStr(const char *str) {
    if (str == NULL)
        return NULL;

    int len = strlen(str);
    char* revStr = malloc(len + 1);
    if (revStr == NULL)
        return NULL;

    for(int i = 0; i < len; i++)
        revStr[i] = str[len-1-i];
    revStr[len] = '\0';

    return revStr;
}

int main() {
    char* str = "Hello World!";
    printf("The original string is: %s\n", str);

    char* reversedStr = reverStr(str);
    if (reversedStr != NULL) {
        printf("The reversed string is: %s\n", reversedStr);
        free(reversedStr);
    } else {
        printf("Error: Failed to allocate memory for the reversed string.\n");
    }
    
    return 0;
}