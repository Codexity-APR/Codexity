#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i, len;
    char *cstring = NULL;

    // Calculate the total length of the C string
    len = 0;
    for (i = 1; i < argc; i++) {
        len += strlen(argv[i]) + 1;  // Add 1 for space or null terminator
    }

    // Allocate memory for the C string
    cstring = (char*) malloc((len + 1) * sizeof(char)); // allocate an extra byte for null terminator

    if (cstring == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Concatenate the command line arguments into the C string
    cstring[0] = '\0';
    for (i = 1; i < argc; i++) {
        // Check if there is enough space to concatenate the argument
        if (strlen(cstring) + strlen(argv[i]) + 1 > len) {
            fprintf(stderr, "Insufficient memory to store concatenated string.\n");
            free(cstring);
            exit(EXIT_FAILURE);
        }
        strcat(cstring, argv[i]);
        strcat(cstring, " ");
    }

    // Print the C string
    printf("%s\n", cstring);

    // Free the C string
    free(cstring);

    return 0;
}