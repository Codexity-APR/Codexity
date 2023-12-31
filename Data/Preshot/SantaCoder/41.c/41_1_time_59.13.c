#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    char *buffer = NULL; // initialize buffer to NULL
    int length;

    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (char*) malloc(length+1); // allocate one byte extra for null terminator

    if (buffer == NULL) {
        fprintf(stderr, "Error allocating buffer\n"); // print error message
        fclose(file); // close the file pointer
        return 1;
    }

    fread(buffer, length, 1, file); // read the contents of file into buffer
    buffer[length] = '\0'; // add null terminator

    fclose(file); // close the file pointer

    fprintf(stdout, "%s\n", buffer); // print the contents of buffer to console

    free(buffer); // free the dynamically allocated memory

    return 0;
}