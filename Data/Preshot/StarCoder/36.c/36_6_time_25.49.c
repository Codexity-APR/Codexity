#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main () {
    FILE *file;
    char str[MAX_SIZE] = {0}; // initializing all elements to 0
    size_t str_len = 0;

    file = fopen("random.txt", "r"); // opening the file in read mode

    if (file) {
        int c;

        while ((c = getc(file)) != EOF && str_len < MAX_SIZE - 1) {
            str[str_len++] = (char) c;
        }

        str[str_len] = '\0'; // adding null terminator at the end of the string

        fclose(file); // closing the file
    }
    else {
        printf("Error: Failed to open file\n");
        return EXIT_FAILURE;
    }

    printf("%s", str); // printing the string

    return EXIT_SUCCESS;
}