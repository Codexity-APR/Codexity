#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str)
{
    if (str == NULL) // Check if input string is NULL
        return NULL;

    size_t len = strlen(str);
    char* revStr = malloc(len + 1); // allocate memory for reversed string

    if (revStr == NULL) // Check if memory allocation failed
        return NULL;

    int i;
    int j = 0;
    for(i = len - 1; i >= 0; i--)
    {
        revStr[j] = str[i];
        j++;
    }
    revStr[j] = '\0';

    return revStr;
}

int main()
{
    const char* str = "Hello, World!";
    char* reversed = reverStr(str);

    if (reversed != NULL) // Check if reverStr returned NULL
    {
        printf("Reversed string: %s\n", reversed);
        free(reversed);
    }
    else
    {
        printf("Failed to reverse the string.\n");
    }

    return 0;
}