#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str)
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    for(i = strlen(str)-1; i >= 0; i--)
    {
        int index = strlen(str) - i - 1;
        revStr[index] = str[i];
    }
    revStr[strlen(str)] = '\0'; // add null character at the end
    return revStr;
}

int main()
{
    const char *inputStr = "Hello, World!";
    char *reversedStr = reverStr(inputStr);
    printf("Reversed String: %s\n", reversedStr);
    free(reversedStr); // free the allocated memory
    return 0;
}