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
    cstring = (char*) malloc((len + 1) * sizeof(char));
    cstring[0] = '\0';
    
    // Concatenate the command line arguments into the C string
    for (i = 1; i < argc; i++) {
        strcat(cstring, argv[i]);
        if (i != argc - 1) {
            strcat(cstring, " ");
        }
    }
    
    // Print the concatenated C string
    printf("Concatenated string: %s\n", cstring);
    
    // Free the allocated memory
    free(cstring);
    
    return 0;
}