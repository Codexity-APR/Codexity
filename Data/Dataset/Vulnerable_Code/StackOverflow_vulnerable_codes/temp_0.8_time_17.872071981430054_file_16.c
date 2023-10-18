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
        printf("Unable to open the file.\n");
        return 1;
    }

    while (fscanf(fp, "%d", &num) != EOF)
    {
        total += num;
    }

    printf("The sum of the numbers in the file is: %d\n", total);

    fclose(fp);

    return 0;
}