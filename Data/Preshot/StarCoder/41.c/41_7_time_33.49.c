#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    buffer = (char*) malloc(length);

    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        fclose(file);
        return 1;
    }

    size_t bytes_read = fread(buffer, 1, length, file);
    if (bytes_read != length) {
        fprintf(stderr, "Error reading file\n");
        fclose(file);
        free(buffer);
        return 1;
    }

    printf("%s\n", buffer);

    fclose(file);
    free(buffer);

    return 0;
}