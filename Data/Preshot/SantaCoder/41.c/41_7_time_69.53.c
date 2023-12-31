#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    char *buffer = NULL;  // Initialize to NULL to prevent undefined behavior
    int length;

    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = malloc(length + 1);  // Add 1 for null terminator

    if (buffer == NULL) {
        fprintf(stderr, "Error allocating buffer\n");
        fclose(file);  // Close file before returning
        return 1;
    }

    if (fread(buffer, length, 1, file) != 1) {  // Check fread return value
        fprintf(stderr, "Error reading file\n");
        free(buffer);  // Free allocated memory before returning
        fclose(file);
        return 1;
    }

    buffer[length] = '\0';  // Add null terminator

    fclose(file);

    printf("%s\n", buffer);  // Use printf instead of fprintf to stdout

    free(buffer);  // Free allocated memory

    return 0;
}