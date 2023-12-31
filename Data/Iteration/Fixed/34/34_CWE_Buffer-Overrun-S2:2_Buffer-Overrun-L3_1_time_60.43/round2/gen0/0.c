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
    cstring = (char*) malloc((len + argc - 1) * sizeof(char));  // Add space for additional separators
    
    // Concatenate the command line arguments into the C string
    int index = 0;
    for (i = 1; i < argc; i++) {
        strcpy(cstring + index, argv[i]);  // Copy argument to cstring
        index += strlen(argv[i]);  // Move index to the end of the copied argument
        if (i < argc - 1) {
            cstring[index++] = ' ';  // Add space after each argument
        }
    }
    cstring[index] = '\0';  // Add null terminator
    
    // Print the concatenated C string
    printf("Concatenated String: %s\n", cstring);
    
    // Free allocated memory
    free(cstring);
    
    return 0;
}