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

    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, CHUNK_SIZE, file)) > 0) {
        fwrite(buffer, 1, bytes_read, stdout);
    }

    free(buffer);
    fclose(file);
    return 0;
}