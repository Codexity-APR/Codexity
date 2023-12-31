#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str) // changed function name to reverseStr
{
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added a variable to track the index of the reversed string array

    for(i = strlen(str)-1; i >= 0; i--)
    {
        revStr[j] = str[i]; // store the characters in reverse order
        j++; // increment the index of the reversed string array
    }

    revStr[j] = '\0'; // add null terminator to the reversed string

    return revStr; // return the reversed string
}

int main()
{
    const char* input = "Hello, world!";
    char* reversedInput = reverseStr(input);

    printf("Reversed string: %s\n", reversedInput);

    free(reversedInput); // free the allocated memory

    return 0;
}