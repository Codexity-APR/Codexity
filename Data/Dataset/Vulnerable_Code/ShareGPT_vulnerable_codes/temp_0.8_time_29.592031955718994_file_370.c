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
        strcat(cstring, argv[i]);  // Concatenate the argument
        index += strlen(argv[i]);  // Update the index position

        if (i != argc - 1) {
            strcat(cstring, " ");  // Add space between arguments
            index++;  // Update the index position for space
        }
    }

    printf("Concatenated String: %s\n", cstring);

    // Free the memory allocated for the C string
    free(cstring);

    return 0;
}