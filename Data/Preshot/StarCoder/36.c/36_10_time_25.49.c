#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main () {
    FILE *file;
    char str[MAX_SIZE];
    size_t len = sizeof(str);

    file = fopen("random.txt", "r"); // opening the file in read mode

    if (file == NULL) {
        fprintf(stderr, "Failed to open file\n");
        exit(1);
    }

    int i = 0;
    char c;
 
    while ((c = getc(file)) != EOF && i < len - 1) { // reading each character until end of file
        str[i++] = c;
    }

    str[i] = '\0'; // adding null terminator at the end of the string

    fclose(file); // closing the file

    printf("%s", str); // printing the string

    return 0;
}