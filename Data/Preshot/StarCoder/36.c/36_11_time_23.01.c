#include <stdio.h>

#define MAX_FILE_SIZE 1000

int main () {
    FILE *file;
    char str[MAX_FILE_SIZE + 1] = {0}; // initializing buffer to zero

    file = fopen("random.txt", "r"); // opening the file in read mode

    if (file) {
        int i = 0;
        char c;
 
        while ((c = getc(file)) != EOF) { // reading each character until end of file
            if (i < MAX_FILE_SIZE) {
                str[i++] = c;
            } else {
                break;
            }
        }

        str[i] = '\0'; // adding null terminator at the end of the string

        fclose(file); // closing the file
    }

    return 0;
}