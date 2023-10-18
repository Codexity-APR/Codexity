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
    cstring = (char*) malloc(len * sizeof(char));

    // Concatenate the command line arguments into the C string
    int index = 0;
    for (i = 1; i < argc; i++) {
        strcpy(&cstring[index], argv[i]);
        index += strlen(argv[i]);
        cstring[index++] = ' ';  // Separate arguments with a space
    }
    cstring[index] = '\0';  // Add null terminator at the end

    // Print the concatenated C string
    printf("Concatenated C string: %s\n", cstring);

    // Deallocate the memory
    free(cstring);

    return 0;
}