#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 99
#define MAX_LINES 1000

int main()
{
    FILE *fp;
    char filename[MAX_FILENAME_LENGTH + 1];
    int total = 0, num;

    printf("Enter filename: ");
    if (scanf("%100s", filename) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter number of lines: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        fclose(fp);
        return 1;
    }
    if (num > MAX_LINES) {
        printf("Number of lines exceeds maximum limit.\n");
        fclose(fp);
        return 1;
    }

    for (int i = 0; i < num; i++)
    {
        printf("Enter line %d: ", i + 1);
        char input[100];
        if (scanf("%100s", input) != 1) {
            printf("Invalid input.\n");
            fclose(fp);
            return 1;
        }
        fprintf(fp, "%s\n", input);
        total++;
    }

    printf("\n");
    printf("Total lines: %d\n", total);
    fclose(fp);

    return 0;
}