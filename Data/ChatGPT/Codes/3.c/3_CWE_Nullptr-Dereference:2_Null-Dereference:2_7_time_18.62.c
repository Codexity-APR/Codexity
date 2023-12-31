#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str)
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added counter variable for reversed string index
    for(i = strlen(str)-1; i >= 0; i--)
    {
        revStr[j] = str[i];
        j++; // increment reversed string index
    }
    revStr[j] = '\0'; // add null terminator at the end of reversed string
    return revStr; // return the reversed string
}

int main(void)
{
    const char* str = "Hello, World!";
    char* reversed = reverStr(str);
    printf("Reversed String: %s\n", reversed);
    free(reversed); // free the memory allocated for reversed string
    return 0;
}