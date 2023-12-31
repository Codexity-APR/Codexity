#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024

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

    buffer = malloc(length + 1);

    if (buffer == NULL) {
        fclose(file);
        fprintf(stderr, "Error allocating buffer\n");
        return 1;
    }

    size_t bytesRead, totalBytesRead = 0;

    while ((bytesRead = fread(buffer + totalBytesRead, 1, CHUNK_SIZE, file))) {
        totalBytesRead += bytesRead;
    }

    fclose(file);

    if (totalBytesRead != length) {
        fprintf(stderr, "Error reading file\n");
        free(buffer);
        return 1;
    }

    buffer[totalBytesRead] = '\0';

    printf("%s", buffer);

    free(buffer);

    return 0;
}