#include <stdio.h>

int main() {
    FILE *file;
    char str[1000] = {0}; // Initialize the array with null characters
    file = fopen("random.txt", "r"); // opening the file in read mode
    if (file) {
        int i = 0;
        char c;
        while ((c = getc(file)) != EOF) { // reading each character until end of file
            str[i++] = c;
        }
        str[i] = '\0'; // adding null terminator at the end of the string
        fclose(file); // closing the file
    }
    // Complete the code below
    printf("Contents of the file: %s\n", str);
    return 0;
}