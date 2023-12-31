#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100

int main()
{
    FILE *fp;
    char filename[MAX_FILENAME_LENGTH + 1]; // add 1 for null terminator
    int total = 0, num;

    printf("Enter filename: ");
    if (scanf("%100s", filename) != 1) { // limit input to 100 characters
        printf("Error reading filename\n");
        return 1;
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(fp, "%d", &num) == 1) {
        total += num;
    }

    printf("Total: %d\n", total);

    fclose(fp);
    return 0;
}