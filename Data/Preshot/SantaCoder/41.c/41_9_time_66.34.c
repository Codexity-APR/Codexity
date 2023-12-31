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
        fprintf(stderr, "Error allocating buffer\n");
        fclose(file);
        return 1;
    }

    if (fread(buffer, length, 1, file) != 1) {
        fprintf(stderr, "Error reading file\n");
        free(buffer);
        fclose(file);
        return 1;
    }

    fclose(file);

    fprintf(stdout, "%s\n", buffer);

    free(buffer);

    return 0;
}