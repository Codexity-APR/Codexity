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

    buffer = (char*) malloc(length+1); // add 1 for null terminator

    if (buffer == NULL) {
        fprintf(stderr, "Error allocating buffer\n");
        fclose(file); // close file before exiting
        return 1;
    }

    fread(buffer, 1, length, file); // read file into buffer
    buffer[length] = '\0'; // add null terminator

    fclose(file); // close file after reading data

    printf("%s\n", buffer); // print buffer to stdout

    free(buffer); // free dynamically allocated memory

    return 0;
}