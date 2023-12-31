#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str)
{
    if (str == NULL) {
        return NULL; // handle null input string
    }

    size_t len = strlen(str);
    char* revStr = malloc(len + 1); // allocate memory for reversed string

    if (revStr == NULL) {
        return NULL; // handle memory allocation failure
    }

    int i;
    int j = 0; // added index variable for reversed string

    for (i = len - 1; i >= 0; i--)
    {
        revStr[j] = str[i]; // store reversed characters in revStr
        j++; // increment index for reversed string
    }

    revStr[j] = '\0'; // add null terminator to the end of reversed string
    return revStr; // return the reversed string
}

int main()
{
    const char* str = "Hello, World!";
    char* reversedStr = reverseStr(str);

    if (reversedStr != NULL) {
        printf("Reversed string: %s\n", reversedStr);
        free(reversedStr); // free the allocated memory
    } else {
        printf("Failed to reverse the string.\n");
    }

    return 0;
}