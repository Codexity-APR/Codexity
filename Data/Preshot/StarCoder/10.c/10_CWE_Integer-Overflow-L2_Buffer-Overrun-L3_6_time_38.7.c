#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_INPUT_LENGTH 10

int main()
{
    FILE *fp;
    char filename[MAX_FILENAME_LENGTH+1];
    int total = 0, num;
    int result;

    printf("Enter filename: ");
    if (fgets(filename, MAX_FILENAME_LENGTH+1, stdin) == NULL)
    {
        fprintf(stderr, "Error reading filename\n");
        exit(1);
    }
    // Remove newline character from end of filename if present
    if (filename[strlen(filename)-1] == '\n')
    {
        filename[strlen(filename)-1] = '\0';
    }

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    while ((result = fscanf(fp, "%d", &num)) == 1)
    {
        total += num;
    }
    if (result != EOF)
    {
        fprintf(stderr, "Error reading file: %s\n", filename);
    }
    else
    {
        printf("Total: %d\n", total);
    }

    fclose(fp);
    return 0;
}