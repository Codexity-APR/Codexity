#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str)
{
    if(str == NULL) return NULL; // check for null input string
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    if(revStr == NULL) return NULL; // check for memory allocation failure
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
    char* revStr = reverStr(str);
    if(revStr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("The reversed string is: %s\n", revStr);
    free(revStr); // free the dynamically allocated memory
    return 0;
}