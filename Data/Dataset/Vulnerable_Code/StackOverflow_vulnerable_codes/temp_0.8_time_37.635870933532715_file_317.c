#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for malloc and free

char* reverseStr(const char *str) {
    char* revStr = malloc(strlen(str) + 1); // allocate memory for reversed string
    int i;
    int j = 0; // added variable to keep track of index in reversed string

    for(i = strlen(str)-1; i >= 0; i--) {
        revStr[j] = str[i]; // store reversed characters in revStr
        j++; // increment j after each iteration
    }

    revStr[j] = '\0'; // add null terminator at the end of reversed string
    return revStr; // return reversed string
}

int main() {
    const char* str = "Hello, World!";
    char* reversed = reverseStr(str);
    printf("Reversed string: %s\n", reversed);
    free(reversed); // deallocate memory allocated for reversed string
    return 0;
}