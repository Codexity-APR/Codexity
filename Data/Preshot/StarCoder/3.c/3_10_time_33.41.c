#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str)
{
    if (str == NULL) {
        return NULL; // handle null input string
    }

    size_t len = strlen(str);
    char* revStr = malloc(len + 1);
    if (revStr == NULL) {
        return NULL; // handle memory allocation failure
    }

    int i;
    for (i = len - 1; i >= 0; i--) {
        revStr[len - i - 1] = str[i];
    }
    revStr[len] = '\0';

    return revStr;
}

int main()
{
    const char* str = "Hello World!";
    printf("The original string is: %s\n", str);

    char* revStr = reverStr(str);
    if (revStr == NULL) {
        fprintf(stderr, "Failed to allocate memory for reversed string\n");
        return 1;
    }

    printf("The reversed string is: %s\n", revStr);
    free(revStr); // free dynamically allocated memory

    return 0;
}