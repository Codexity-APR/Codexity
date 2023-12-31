#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i, len = 0;
    char *cstring = NULL;

    // Calculate the total length of the C string
    for (i = 1; i < argc; i++) {
        len += strlen(argv[i]) + 1;  // Add 1 for space or null terminator
    }

    // Allocate memory for the C string
    cstring = (char*) malloc(len * sizeof(char));
    if (cstring == NULL) {
        printf("Error: Failed to allocate memory for C string.\n");
        return -1;
    }

    // Concatenate the command line arguments into the C string
    len = 0;
    for (i = 1; i < argc; i++) {
        strncpy(cstring + len, argv[i], strlen(argv[i]));
        len += strlen(argv[i]);  // Add the length of the current argument
        cstring[len++] = ' ';  // Add a space after the current argument
    }

    cstring[len] = '\0';  // Add a null terminator at the end of the C string

    // Print the C string to stdout
    printf("%s\n", cstring);

    // Free the allocated memory
    free(cstring);

    return 0;
}