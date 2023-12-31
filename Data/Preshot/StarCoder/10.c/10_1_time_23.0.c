#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    FILE *fp;
    char filename[100];
    int total = 0, num;

    printf("Enter filename: ");
    if (scanf("%99s", filename) != 1) {
        printf("Invalid input\n");
        exit(1);
    }
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