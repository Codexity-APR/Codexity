#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *ptr;
    ptr = fopen("D:\\f4.txt", "r+");
    if (ptr == NULL) {
        printf("file cant be opened");
        exit(0);
    }
    int ch = fgetc(ptr); // Store the return value of fgetc() in an int variable
    while (ch != EOF) {
        // Add your code here to process the characters from the file
        ch = fgetc(ptr);
    }
    fclose(ptr);
    return 0;
}