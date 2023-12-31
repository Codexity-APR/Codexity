#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str)
{
    if (str == NULL) {
        return NULL; // handle null input string
    }

    size_t len = strlen(str);
    char* revStr = malloc(len + 1); // allocate memory for reversed string

    if (revStr == NULL) {
        return NULL; // handle memory allocation failure
    }

    int i;
    int j = 0; // added a counter variable to keep track of the reversed string index

    for (i = len - 1; i >= 0; i--)
    {
        revStr[j] = str[i]; // store the characters in reverse order
        j++; // increment the counter
    }

    revStr[j] = '\0'; // add null terminator at the end of the reversed string
    return revStr; // return the reversed string
}

int main()
{
    const char* str = "Hello, World!";
    char* reversed = reverseStr(str);

    if (reversed != NULL) {
        printf("Reversed String: %s\n", reversed);
        free(reversed); // free the dynamically allocated memory
    } else {
        printf("Failed to reverse the string.\n");
    }

    return 0;
}