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
    int pos = 0;
    for (i = 1; i < argc; i++) {
        strcpy(cstring + pos, argv[i]);   // Copy the argument to the C string
        pos += strlen(argv[i]);           // Move the position pointer to the end of the argument
        cstring[pos++] = ' ';             // Add a space between the arguments
    }
    cstring[pos-1] = '\0';                // Replace the last space with a null terminator

    // Print the C string to stdout
    printf("%s", cstring);

    // Free the allocated memory
    free(cstring);

    return 0;
}