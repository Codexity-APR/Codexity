#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[100];
    int total = 0, num;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%d", &num) != EOF)
    {
        total += num;
    }

    printf("The sum of the numbers in %s is %d.\n", filename, total);

    fclose(fp);

    return 0;
}
