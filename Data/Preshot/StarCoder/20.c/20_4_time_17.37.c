#include <stdio.h>
#include <stdlib.h>

int main() {
    int ch;
    FILE *ptr;

    ptr = fopen("D:\\f4.txt", "r+");
    if (ptr == NULL) {
        printf("Error opening file.");
        exit(0);
    }

    ch = fgetc(ptr);
    while (ch != EOF) {
        printf("%c", ch);
        ch = fgetc(ptr);
    }

    fclose(ptr);
    return 0;
}