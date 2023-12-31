#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str) // changed return type to char*
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added a new variable to keep track of the index of revStr
    
    for(i = strlen(str)-1; i >= 0; i--)
    {
        revStr[j] = str[i]; // assign the reversed characters to revStr
        j++; // increment j after each assignment
    }
    
    revStr[j] = '\0'; // add a null terminator at the end of revStr
    
    return revStr; // return the reversed string
}

int main()
{
    const char* str = "Hello, World!";
    char* reversed = reverStr(str);
    
    printf("Reversed string: %s\n", reversed);
    
    free(reversed); // free the dynamically allocated memory
    
    return 0;
}