#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str)
{
    if (str == NULL) {
        return NULL;
    }

    size_t len = strlen(str);
    char* revStr = malloc(len + 1); // allocate memory for reversed string

    if (revStr == NULL) {
        return NULL;
    }

    int i;
    int j = 0;

    for (i = len - 1; i >= 0; i--)
    {
        revStr[j] = str[i];
        j++;
    }

    revStr[j] = '\0'; // add null terminator to the reversed string
    return revStr;
}

int main()
{
    const char *input = "Hello, World!";
    char *reversed = reverseStr(input);

    if (reversed != NULL) {
        printf("Reversed string: %s\n", reversed);
        free(reversed); // free the allocated memory
    } else {
        printf("Failed to reverse the string.\n");
    }

    return 0;
}