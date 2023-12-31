#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_NUM_LINES 100

int main()
{
    FILE *fp;
    char filename[MAX_FILENAME_LENGTH];
    int total = 0, num;

    printf("Enter filename: ");
    if (fgets(filename, MAX_FILENAME_LENGTH, stdin) == NULL)
    {
        printf("Error reading file name\n");
        return 1;
    }
    filename[strcspn(filename, "\n")] = '\0'; // remove newline character if present

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    printf("Enter number of lines (max %d): ", MAX_NUM_LINES);
    if (scanf("%d", &num) != 1 || num <= 0 || num > MAX_NUM_LINES)
    {
        printf("Invalid number of lines\n");
        return 1;
    }

    for (int i = 0; i < num; i++)
    {
        printf("Line %d: ", i+1);
        char line[100];
        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            printf("Error reading input\n");
            return 1;
        }
        fprintf(fp, "%s", line);
        total++;
    }

    printf("\n");
    printf("Total lines written to file: %d\n", total);
    fclose(fp);

    return 0;
}