#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i, len;
    char *cstring;

    // Calculate the total length of the C string
    len = 0;
    for (i = 1; i < argc; i++) {
        if (argv[i] != NULL) {
            len += strlen(argv[i]) + 1;  // Add 1 for space or null terminator
        }
    }

    // Allocate memory for the C string
    cstring = (char*) calloc(len + 1, sizeof(char));  // Add 1 for null terminator

    if (cstring == NULL) {
        printf("Error: Unable to allocate memory\n");
        return -1;
    }

    // Concatenate the command line arguments into the C string
    cstring[0] = '\0';
    for (i = 1; i < argc; i++) {
        if (argv[i] != NULL) {
            strcat(cstring, argv[i]);
            strcat(cstring, " ");
        }
    }

    // Print the C string
    printf("%s\n", cstring);

    // Free the C string
    free(cstring);

    return 0;
}