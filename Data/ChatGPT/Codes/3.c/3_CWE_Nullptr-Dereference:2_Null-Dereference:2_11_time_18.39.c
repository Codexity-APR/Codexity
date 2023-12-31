#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char* str) {
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    for (i = strlen(str) - 1; i >= 0; i--) {
        revStr[strlen(str) - 1 - i] = str[i]; // store reversed characters in revStr
    }
    revStr[strlen(str)] = '\0'; // add null terminator at the end

    return revStr;
}

int main() {
    const char* str = "Hello World!";
    char* reversed = reverseStr(str);

    printf("Original String: %s\n", str);
    printf("Reversed String: %s\n", reversed);

    free(reversed); // free the allocated memory

    return 0;
}