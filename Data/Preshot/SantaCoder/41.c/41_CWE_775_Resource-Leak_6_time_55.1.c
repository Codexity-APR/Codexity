#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char*) malloc(length + 1);

    if (buffer == NULL) {
        fprintf(stderr, "Error allocating buffer\n");
        return 1;
    }

    fread(buffer, length, 1, file);
    buffer[length] = '\0';

    fclose(file);

    printf("%s\n", buffer);

    free(buffer);

    return 0;
}