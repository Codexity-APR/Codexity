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
    cstring = (char*) malloc((len + 1) * sizeof(char));
    if (cstring == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Concatenate the command line arguments into the C string
    len = 0;
    for (i = 1; i < argc; i++) {
        strcpy(cstring + len, argv[i]);
        len += strlen(argv[i]);  
        cstring[len] = ' '; // Add space after each argument
        len++;  // Increment len to point to the next character
    }
    cstring[len - 1] = '\0';  // Replace last space with null terminator

    // Print the C string to stdout
    printf("%s\n", cstring);

    // Free the memory allocated for cstring
    free(cstring);

    return 0;
}