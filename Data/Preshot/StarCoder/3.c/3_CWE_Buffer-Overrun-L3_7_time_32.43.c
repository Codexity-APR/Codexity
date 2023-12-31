#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str)
{
    if (str == NULL) {
        return NULL;
    }

    int len = strlen(str);
    char* revStr = malloc(len + 1);

    if (revStr == NULL) {
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        revStr[i] = str[len - i - 1];
    }

    revStr[len] = '\0';
    return revStr;
}

int main()
{
    const char* str = "Hello World!";
    printf("The original string is: %s\n", str);

    char* reversedStr = reverStr(str);
    if (reversedStr != NULL) {
        printf("The reversed string is: %s\n", reversedStr);
        free(reversedStr);
    } else {
        printf("Failed to allocate memory for reversed string.\n");
    }

    return 0;
}