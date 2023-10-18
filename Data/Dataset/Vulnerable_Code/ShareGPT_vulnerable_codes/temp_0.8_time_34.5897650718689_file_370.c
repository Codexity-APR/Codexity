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
    int position = 0;
    for (i = 1; i < argc; i++) {
        strcpy(cstring + position, argv[i]);  // Copy argument to cstring
        position += strlen(argv[i]);  // Move position to the end of the copied argument
        cstring[position] = ' ';  // Add space after the argument
        position++;  // Move position to the next empty space
    }
    cstring[position - 1] = '\0';  // Replace the last space with null terminator

    // Print the concatenated string
    printf("Concatenated String: %s\n", cstring);

    // Free the allocated memory
    free(cstring);

    return 0;
}