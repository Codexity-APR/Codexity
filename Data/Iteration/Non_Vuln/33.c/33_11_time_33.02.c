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
        int j;
        int argLen = strlen(argv[i]);

        // Copy each character from the argument into the C string
        for (j = 0; j < argLen; j++) {
            cstring[index] = argv[i][j];
            index++;
        }

        // Add a space after each argument (except the last one)
        if (i < argc - 1) {
            cstring[index] = ' ';
            index++;
        }
    }

    // Add null terminator at the end
    cstring[index] = '\0';

    // Print the concatenated string
    printf("Concatenated string: %s\n", cstring);

    // Free the allocated memory
    free(cstring);

    return 0;
}