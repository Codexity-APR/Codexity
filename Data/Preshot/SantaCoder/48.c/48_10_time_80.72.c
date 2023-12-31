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

    size_t bytes_read, bytes_written;
    while (length > 0) {
        if (length < CHUNK_SIZE) {
            bytes_read = fread(buffer, 1, length, file);
            bytes_written = fwrite(buffer, 1, bytes_read, stdout);
        } else {
            bytes_read = fread(buffer, 1, CHUNK_SIZE, file);
            bytes_written = fwrite(buffer, 1, bytes_read, stdout);
        }
        if (bytes_written < bytes_read) {
            fprintf(stderr, "Error writing to file\n");
            free(buffer);
            fclose(file);
            return 1;
        }
        length -= bytes_read;
    }

    free(buffer);
    fclose(file);
    return 0;
}