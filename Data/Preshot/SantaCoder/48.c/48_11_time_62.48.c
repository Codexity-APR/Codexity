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
        fclose(file); // close the file before returning
        return 1;
    }

    while (length > 0) {
        int read_size = (length < CHUNK_SIZE) ? length : CHUNK_SIZE; // make sure we don't read beyond the end of file
        fread(buffer, sizeof(char), read_size, file); // read from file into buffer
        fwrite(buffer, sizeof(char), read_size, stdout); // write buffer to stdout
        length -= read_size;
    }

    free(buffer); // free the dynamically allocated memory
    fclose(file); // close the file after use
    return 0;
}