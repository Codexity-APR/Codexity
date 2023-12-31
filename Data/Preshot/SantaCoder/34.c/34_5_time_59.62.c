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

    if (cstring != NULL) {
        // Concatenate the command line arguments into the C string
        for (i = 1; i < argc; i++) {
            strncat(cstring, argv[i], strlen(argv[i]));
            if (i != argc - 1) {
                strncat(cstring, " ", 1);
            }
        }

        // Print the C string to stdout
        printf("%s\n", cstring);

        // Free the dynamically allocated memory
        free(cstring);
        cstring = NULL;
    } else {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    return 0;
}