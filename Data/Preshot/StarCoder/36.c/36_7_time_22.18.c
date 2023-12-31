#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main () {
    FILE *file = NULL;
    char str[MAX_SIZE] = {0}; // initializing the char array with 0
    size_t i = 0;
    char c = '\0';

    file = fopen("random.txt", "r"); // opening the file in read mode

    if (file) {
        while ((c = getc(file)) != EOF && i < MAX_SIZE - 1) { // reading each character until end of file or max size
            str[i++] = c;
        }
        str[i] = '\0'; // adding null terminator at the end of the string
        fclose(file); // closing the file
    } else {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("%s", str); // printing the string

    return 0;
}