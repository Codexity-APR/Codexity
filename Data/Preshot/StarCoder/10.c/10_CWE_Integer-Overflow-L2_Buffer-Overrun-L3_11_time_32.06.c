#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    FILE *fp;
    char filename[100];
    int total = 0, num;
    
    printf("Enter filename: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL)
    {
        printf("Error reading filename\n");
        exit(1);
    }
    // remove newline character if present
    if (filename[strlen(filename)-1] == '\n')
        filename[strlen(filename)-1] = '\0';

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while (fscanf(fp, "%d", &num) == 1)
    {
        // check for integer overflow
        if (total > INT_MAX - num)
        {
            printf("Integer overflow detected\n");
            exit(1);
        }
        total += num;
    }
    printf("Total: %d\n", total);
    fclose(fp);
    return 0;
}