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
        printf("Memory allocation failed\n");
        return 1;
    }

    // Concatenate the command line arguments into the C string
    len = 0;
    for (i = 1; i < argc; i++) {
        memcpy(cstring + len, argv[i], strlen(argv[i]));
        len += strlen(argv[i]); // Add length of current argument
        if(i != argc - 1) {
            cstring[len] = ' '; // Add space separator if not the last argument
            len += 1;
        }
    }
    cstring[len] = '\0'; // Add null terminator to the end of C string

    // Print the C string to stdout
    printf("%s\n", cstring);

    // Free the allocated memory
    free(cstring);

    return 0;
}