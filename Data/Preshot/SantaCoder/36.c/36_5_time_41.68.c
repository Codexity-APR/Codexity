#include <stdio.h>

int main () {
    FILE *file;
    char str[1000]; // assuming the file is no longer than 1000 characters

    file = fopen("random.txt", "r"); // opening the file in read mode

    if (file) {
        int i = 0;
        char c;
 
        while ((c = getc(file)) != EOF) { // reading each character until end of file
            str[i++] = c;
        }

        str[i] = '\0'; // adding null terminator at the end of the string

        fclose(file); // closing the file

        printf("The contents of the file are: \n%s", str); // printing the content of the file
    } else {
        printf("Unable to open file."); // error message if file could not be opened
    }

    return 0;
}