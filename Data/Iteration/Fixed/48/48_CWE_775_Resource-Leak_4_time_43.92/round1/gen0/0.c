#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    char *buffer;
    int length;

    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (char*) malloc(length);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        fclose(file); // Close the file before returning
        return 1;
    }

    fread(buffer, length, 1, file);
    fclose(file);

    // Code to use the buffer goes here

    free(buffer); // Free the allocated memory

    return 0;
}