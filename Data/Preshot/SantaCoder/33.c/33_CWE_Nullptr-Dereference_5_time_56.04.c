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
    cstring = (char*) malloc((len + 1) * sizeof(char));  // Add 1 for null terminator

    // Concatenate the command line arguments into the C string
    len = 0;
    for (i = 1; i < argc; i++) {
        memcpy(cstring + len, argv[i], strlen(argv[i]));
        len += strlen(argv[i]);  // Add length of current argument
        if (i != argc - 1) {
            cstring[len] = ' ';  // Add space if this is not the last argument
            len++;
        }
    }
    cstring[len] = '\0';  // Add null terminator at the end of the C string

    // Print the C string to stdout
    printf("%s", cstring);

    free(cstring);  // Free the dynamically allocated memory

    return 0;
}