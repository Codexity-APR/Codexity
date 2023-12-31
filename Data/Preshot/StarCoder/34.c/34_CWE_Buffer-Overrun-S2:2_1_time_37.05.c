#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i, len;
    char *cstring = NULL;

    // Check if there are enough arguments to concatenate
    if (argc < 2) {
        printf("Please provide command line arguments to concatenate.\n");
        return 1;
    }

    // Calculate the total length of the C string
    len = 0;
    for (i = 1; i < argc; i++) {
        len += strlen(argv[i]) + 1;  // Add 1 for space or null terminator
    }

    // Allocate memory for the C string
    cstring = (char*) malloc(len * sizeof(char));

    // Check if memory allocation was successful
    if (cstring == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Concatenate the command line arguments into the C string
    cstring[0] = '\0';
    for (i = 1; i < argc; i++) {
        strcat(cstring, argv[i]);
        if (i < argc - 1) {
            strcat(cstring, " ");
        }
    }

    // Print the C string
    printf("%s\n", cstring);

    // Free the C string
    free(cstring);

    return 0;
}