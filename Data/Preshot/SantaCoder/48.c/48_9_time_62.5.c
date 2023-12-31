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
        fprintf(stderr, "Error allocating buffer\n");
        fclose(file);
        return 1;
    }

    while (length > 0) {
        int chunk_size = (length > CHUNK_SIZE) ? CHUNK_SIZE : length;
        fread(buffer, 1, chunk_size, file);
        fwrite(buffer, 1, chunk_size, stdout);
        length -= chunk_size;
    }

    fclose(file);
    free(buffer);
    return 0;
}