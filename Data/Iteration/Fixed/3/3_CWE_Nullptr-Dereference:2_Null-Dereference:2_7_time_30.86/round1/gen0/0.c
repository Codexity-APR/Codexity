#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char* str) {
    if (str == NULL) {
        return NULL; // handle null input string
    }

    size_t len = strlen(str);
    char* revStr = malloc(len + 1); // allocate memory for reversed string

    if (revStr == NULL) {
        return NULL; // handle memory allocation failure
    }

    for (int i = len - 1; i >= 0; i--) {
        revStr[len - 1 - i] = str[i]; // store reversed characters in revStr
    }

    revStr[len] = '\0'; // add null terminator at the end
    return revStr;
}

int main() {
    const char* str = "Hello World!";
    char* reversed = reverseStr(str);

    if (reversed != NULL) {
        printf("Original String: %s\n", str);
        printf("Reversed String: %s\n", reversed);
        free(reversed); // free the allocated memory
    } else {
        printf("Failed to reverse the string.\n");
    }

    return 0;
}