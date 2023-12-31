#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i, len;
    char *cstring;

    // Calculate the total length of the C string
    len = 0;
    for (i = 1; i < argc; i++) {
        len += strlen(argv[i]) + 1;  // Add 1 for space or null terminator
    }

    // Allocate memory for the C string
    cstring = (char*) malloc(len * sizeof(char));
    if (cstring == NULL) {
        printf("Failed to allocate memory for the string!\n");
        return 1;
    }
    memset(cstring, 0, len);  // Initialize the string to all null characters

    // Concatenate the command line arguments into the C string
    len = 0;
    for (i = 1; i < argc; i++) {
        strncpy(cstring + len, argv[i], strlen(argv[i]));
        len += strlen(argv[i]);  // Add the length of the current argument
        cstring[len++] = ' ';  // Add a space character
    }
    cstring[len - 1] = '\0';  // Replace the last space with a null terminator

    // Print the C string to stdout
    printf("%s\n", cstring);

    // Free the dynamically allocated memory
    free(cstring);

    return 0;
}