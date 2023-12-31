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
    
    // Allocate memory for the C string and initialize with null terminators
    cstring = (char*) malloc((len + 1) * sizeof(char));
    
    // Check if memory allocation was successful
    if (cstring == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    memset(cstring, '\0', (len + 1) * sizeof(char));
    
    // Concatenate the command line arguments into the C string
    int index = 0;
    for (i = 1; i < argc; i++) {
        strcat(cstring, argv[i]); // Append the argument to the C string
        strcat(cstring, " "); // Add a space after each argument
    }
    
    printf("Concatenated String: %s\n", cstring);
    
    // Free the allocated memory
    free(cstring);
    
    return 0;
}