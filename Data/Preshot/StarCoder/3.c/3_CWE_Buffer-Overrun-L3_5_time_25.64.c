#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverseStr(const char *str) {
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

int main() {
    const char* str = "Hello, World!";
    printf("The original string is: %s\n", str);
    char* revStr = reverseStr(str);
    if (revStr == NULL) {
        printf("Error: memory allocation failed.\n");
        return 1;
    }
    printf("The reversed string is: %s\n", revStr);
    free(revStr);
    return 0;
}