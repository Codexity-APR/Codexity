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
        int read_size = length > CHUNK_SIZE ? CHUNK_SIZE : length;
        int bytes_read = fread(buffer, 1, read_size, file);
        if (bytes_read != read_size) {
            fprintf(stderr, "Error reading file\n");
            fclose(file);
            free(buffer);
            return 1;
        }
        fwrite(buffer, 1, read_size, stdout);
        length -= bytes_read;
    }

    fclose(file);
    free(buffer);
    return 0;
}