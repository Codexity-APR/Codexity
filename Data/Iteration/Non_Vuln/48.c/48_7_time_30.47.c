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
        fprintf(stderr, "Memory allocation error\n");
        fclose(file);
        return 1;
    }

    if (fread(buffer, 1, length, file) != length) {
        fprintf(stderr, "Error reading file\n");
        fclose(file);
        free(buffer);
        return 1;
    }

    // Add your code here

    fclose(file);
    free(buffer);

    return 0;
}