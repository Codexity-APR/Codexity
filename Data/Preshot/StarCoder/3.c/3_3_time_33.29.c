#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverStr(const char *str)
{
    if(str == NULL) // check if input string is NULL
        return NULL;
    
    int len = strlen(str);
    char* revStr = malloc(len + 1); // allocate memory for reversed string
    
    if(revStr == NULL) // check if memory allocation failed
        return NULL;
    
    int i;
    for(i = len-1; i >= 0; i--)
        revStr[len-i-1] = str[i];
    revStr[len] = '\0';
    
    return revStr;
}

int main()
{
    char* str = "Hello World!";
    printf("The original string is: %s\n", str);
    
    char* revStr = reverStr(str);
    if(revStr == NULL) // check if memory allocation failed
    {
        printf("Memory allocation failed!");
        return 1;
    }
    
    printf("The reversed string is: %s\n", revStr);
    
    free(revStr); // free the allocated memory
    
    return 0;
}