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

    buffer = (char*) malloc(length + 1);

    if (buffer == NULL) {
        fclose(file);
        fprintf(stderr, "Error allocating buffer\n");
        return 1;
    }

    size_t bytesRead = 0;
    while (bytesRead < length) {
        size_t bytesToRead = CHUNK_SIZE;
        if (bytesRead + bytesToRead > length) {
            bytesToRead = length - bytesRead;
        }
        size_t bytesReadThisTime = fread(&buffer[bytesRead], 1, bytesToRead, file);
        if (bytesReadThisTime != bytesToRead) {
            fprintf(stderr, "Error reading file\n");
            fclose(file);
            free(buffer);
            return 1;
        }
        bytesRead += bytesReadThisTime;
    }

    fclose(file);
    buffer[length] = '\0';
    printf("%s", buffer);
    free(buffer);

    return 0;
}