#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i, len;
    char *cstring = NULL; // Initialize cstring to NULL

    // Calculate the total length of the C string
    len = 0;
    for (i = 1; i < argc; i++) {
        len += strlen(argv[i]) + 1;  // Add 1 for space or null terminator
    }

    // Allocate memory for the C string
    cstring = (char*) malloc((len + 1) * sizeof(char));  // Add 1 for null terminator

    if (cstring == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Return an error code
    }

    // Initialize the allocated memory
    memset(cstring, 0, (len + 1) * sizeof(char));

    // Concatenate the command line arguments into the C string
    int index = 0;
    for (i = 1; i < argc; i++) {
        strcat(cstring, argv[i]);
        index += strlen(argv[i]);
        if (i < argc - 1) {
            cstring[index] = ' ';  // Add space between arguments
            index++;
        }
    }
    cstring[index] = '\0';  // Add null terminator

    // Print the concatenated C string
    printf("Concatenated string: %s\n", cstring);

    // Free the allocated memory
    free(cstring);

    return 0;
}