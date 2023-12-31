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
        int arg_length = strlen(argv[i]);
        strncpy(cstring + index, argv[i], arg_length);
        index += arg_length;
        cstring[index] = ' ';
        index++;
    }

    // Null-terminate the C string
    cstring[len] = '\0';

    // Print the resulting C string
    printf("Concatenated String: %s\n", cstring);

    // Free the allocated memory
    free(cstring);

    return 0;
}