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
    int index = 0;
    for (i = 1; i < argc; i++) {
        strncpy(cstring + index, argv[i], strlen(argv[i]));
        index += strlen(argv[i]);
        if (i < argc - 1) {
            cstring[index++] = ' ';  // Add space between arguments
        }
    }
    cstring[index] = '\0';  // Null terminate the string

    // Print the concatenated string
    printf("Concatenated String: %s\n", cstring);

    // Free dynamically allocated memory
    free(cstring);

    return 0;
}