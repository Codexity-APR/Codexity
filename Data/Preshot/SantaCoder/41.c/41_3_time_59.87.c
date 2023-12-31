#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    char *buffer = NULL;
    int length;

    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (char*) malloc(length + 1);  // Add one extra byte for null terminator

    if (buffer == NULL) {
        fprintf(stderr, "Error allocating buffer\n");
        fclose(file);  // Close file before returning
        return 1;
    }

    fread(buffer, 1, length, file);  // Read file into buffer
    buffer[length] = '\0';  // Add null terminator

    fclose(file);  // Close file

    printf("%s\n", buffer);

    free(buffer);  // Free the dynamically allocated buffer

    return 0;
}