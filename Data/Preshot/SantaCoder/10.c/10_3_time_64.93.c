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
        printf("Error: Invalid input.\n");
        return EXIT_FAILURE;
    }

    fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: Unable to open file %s\n", filename);
        return EXIT_FAILURE;
    }

    printf("Enter number of lines: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Invalid input.\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num; i++)
    {
        printf("%d ", fp->read(1)); // This line is incorrect, remove it or replace with appropriate code.
        total++;
    }

    printf("\n");
    printf("Total lines: %d\n", total);
    fclose(fp);

    return EXIT_SUCCESS;
}