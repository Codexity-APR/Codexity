#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100

int main()
{
    FILE *fp;
    char filename[MAX_FILENAME_LENGTH];
    int total = 0, num;

    printf("Enter filename: ");
    if (fgets(filename, MAX_FILENAME_LENGTH, stdin) == NULL)
    {
        printf("Error reading filename\n");
        exit(1);
    }
    filename[strcspn(filename, "\n")] = '\0'; // remove newline character from filename

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf(fp, "%d", &num) == 1)
    {
        total += num;
    }

    printf("Total: %d\n", total);
    fclose(fp);

    return 0;
}