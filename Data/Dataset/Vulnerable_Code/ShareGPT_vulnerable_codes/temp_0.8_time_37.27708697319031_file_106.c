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
        return 1;
    }

    if (fread(buffer, length, 1, file) != 1) {
        fprintf(stderr, "Error reading file\n");
        free(buffer);
        return 1;
    }

    fclose(file);

    // TODO: Add your code here

    free(buffer);
    return 0;
}