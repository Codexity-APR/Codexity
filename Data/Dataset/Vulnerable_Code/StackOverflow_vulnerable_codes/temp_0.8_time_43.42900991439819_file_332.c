#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverStr(const char *str) // changed return type to char*
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0;
  
    for(i = strlen(str)-1; i >= 0; i--) {
        revStr[j] = str[i]; // copy characters in reverse order
        j++;
    }
  
    revStr[j] = '\0'; // add null character at the end of reversed string
    return revStr; // return the reversed string
}

int main() {
    const char* input = "Hello, World!";
    char* reversed = reverStr(input);
    printf("Reversed String: %s\n", reversed);
    free(reversed); // free the allocated memory
    return 0;
}