#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_SIZE 100
#define MAX_INPUT_SIZE 10

int main()
{
    FILE *fp;
    char filename[MAX_FILENAME_SIZE];
    int total = 0, num;
    char input[MAX_INPUT_SIZE];

    printf("Enter filename: ");
    if (fgets(filename, MAX_FILENAME_SIZE, stdin) == NULL)
    {
        printf("Error reading filename\n");
        exit(1);
    }

    // remove the newline character from the filename
    filename[strcspn(filename, "\n")] = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while (fgets(input, MAX_INPUT_SIZE, fp) != NULL)
    {
        if (sscanf(input, "%d", &num) != 1)
        {
            printf("Error reading file\n");
            exit(1);
        }
        total += num;
    }
    printf("Total: %d\n", total);
    fclose(fp);
    return 0;
}