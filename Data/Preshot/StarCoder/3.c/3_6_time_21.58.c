#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str)
{
    if (str == NULL) return NULL; // check for null pointer input
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    if (revStr == NULL) return NULL; // check if memory allocation failed
    int i;
    for(i = strlen(str)-1; i >= 0; i--)
	revStr[strlen(str)-1-i] = str[i]; // reverse the string
    revStr[strlen(str)] = '\0'; // add null terminator
    return revStr;
}

int main()
{
    char* str = "Hello World!";
    printf("The original string is: %s\n", str);
    char* reversedStr = reverStr(str);
    if (reversedStr != NULL) {
        printf("The reversed string is: %s\n", reversedStr);
        free(reversedStr); // free allocated memory
    }
    return 0;
}