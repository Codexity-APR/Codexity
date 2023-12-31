#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *file;
    char str[1000] = {0}; // initializing array with zeroes

    file = fopen("random.txt", "r"); // opening the file in read mode

    if (file) {
        int i = 0;
        char c;
 
        while ((c = getc(file)) != EOF) { // reading each character until end of file
            str[i++] = c;
        }

        str[i] = '\0'; // adding null terminator at the end of the string

        fclose(file); // closing the file
    } else {
        printf("Error: unable to open file.\n");
        exit(EXIT_FAILURE); // exiting the program with failure code
    }

    printf("%s", str); // printing the string

    return 0;
}