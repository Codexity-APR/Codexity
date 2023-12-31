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
    cstring = (char*) malloc((len + 1) * sizeof(char));
    if (cstring == NULL) {
        printf("Error: Unable to allocate memory for the C string.\n");
        return -1;
    }

    // Concatenate the command line arguments into the C string
    for (i = 1; i < argc; i++) {
        strncat(cstring, argv[i], len);
        len -= strlen(argv[i]);
        if (len > 0) {
           strncat(cstring, " ", len);
           len--;
        }
    }

    // Print the C string to stdout
    printf("%s\n", cstring);

    // Free the allocated memory
    free(cstring);

    return 0;
}