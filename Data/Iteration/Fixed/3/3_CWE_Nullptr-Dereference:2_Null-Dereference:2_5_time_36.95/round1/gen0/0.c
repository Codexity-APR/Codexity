#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char* str)
{
    if (str == NULL) {
        return NULL;  // handle null input string
    }

    size_t len = strlen(str);
    char* revStr = malloc(len + 1); // allocate memory for reversed string

    if (revStr == NULL) {
        return NULL;  // handle memory allocation failure
    }

    int i;
    int j = 0;  // added counter for reversed string index
    for (i = len - 1; i >= 0; i--)
    {
        revStr[j] = str[i];  // assign characters in reverse order
        j++;  // increment counter
    }
    revStr[j] = '\0';  // add null-terminating character
    return revStr;  // return reversed string
}

int main()
{
    const char* str = "Hello, World!";
    char* reversed = reverseStr(str);

    if (reversed == NULL) {
        printf("Failed to reverse the string.\n");
        return 1;  // handle failure to reverse string
    }

    printf("Original String: %s\n", str);
    printf("Reversed String: %s\n", reversed);
    free(reversed);  // deallocate memory
    return 0;
}