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
        printf("Error: invalid input for filename\n");
        return 1;
    }

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: failed to open file %s\n", filename);
        return 1;
    }

    printf("Enter number of lines: ");
    if (scanf("%d", &num) != 1 || num < 0 || num > INT_MAX) {
        printf("Error: invalid input for number of lines\n");
        fclose(fp);
        return 1;
    }

    for (int i = 0; i < num; i++)
    {
        printf("%d ", fp->read(1)); // This line is still vulnerable, since it reads from the file without checking for errors or EOF
        total++;
    }

    printf("\n");
    printf("Total lines: %d\n", total);
    fclose(fp);

    return 0;
}