#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i, len = 0;
    char *cstring;

    // Calculate the total length of the C string
    for (i = 1; i < argc; i++) {
        len += strlen(argv[i]) + 1;  // Add 1 for space or null terminator
    }

    // Allocate memory for the C string
    cstring = (char*) malloc(len * sizeof(char));
    if (cstring == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    cstring[0] = '\0';  // Initialize the string as empty

    // Concatenate the command line arguments into the C string
    for (i = 1; i < argc; i++) {
        strncat(cstring, argv[i], len - strlen(cstring) - 1);
        strncat(cstring, " ", 1);  // Add space separator between arguments
    }

    // Print the C string to stdout
    printf("%s\n", cstring);

    // Free the memory allocated for the C string
    free(cstring);

    return 0;
}