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
    
    // Allocate memory for the C string and initialize with null terminator
    cstring = (char*) malloc((len + argc) * sizeof(char)); // Increase the allocation size
    
    if (cstring == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    cstring[0] = '\0';
    
    // Concatenate the command line arguments into the C string
    for (i = 1; i < argc; i++) {
        strcat(cstring, argv[i]);  // Concatenate each argument
        strcat(cstring, " ");  // Add a space after each argument
    }
    
    printf("Concatenated string: %s\n", cstring);
    
    // Free the allocated memory
    free(cstring);
    
    return 0;
}