#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[100];
    int total = 0, num;

    printf("Enter filename: ");
    if (scanf("%99s", filename) != 1) {
        printf("Error: Failed to read filename\n");
        return 1;
    }

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Failed to open file\n");
        return 1;
    }

    printf("Enter number of lines: ");
    if (scanf("%d", &num) != 1) {
        printf("Error: Failed to read number of lines\n");
        return 1;
    }

    for (int i = 0; i < num; i++) {
        char line[100];
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Warning: End of input reached\n");
            break;
        }
        fprintf(fp, "%s", line);
        total++;
    }

    printf("Total lines: %d\n", total);
    fclose(fp);

    return 0;
}