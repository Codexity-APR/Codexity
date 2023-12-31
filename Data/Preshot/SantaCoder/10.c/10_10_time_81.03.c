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
        fprintf(stderr, "Failed to read filename\n");
        exit(EXIT_FAILURE);
    }
    fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("Enter number of lines: ");
    if (scanf("%d", &num) != 1) {
        fprintf(stderr, "Failed to read number of lines\n");
        exit(EXIT_FAILURE);
    }
    if (num <= 0) {
        fprintf(stderr, "Number of lines should be greater than 0\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num; i++) {
        printf("Enter line %d: ", i+1);
        char line[LINE_MAX];
        if (fgets(line, LINE_MAX, stdin) == NULL) {
            fprintf(stderr, "Failed to read line %d\n", i+1);
            exit(EXIT_FAILURE);
        }
        if (fputs(line, fp) == EOF) {
            fprintf(stderr, "Failed to write line %d to file\n", i+1);
            exit(EXIT_FAILURE);
        }
        total++;
    }

    printf("\n");
    printf("Total lines written to file: %d\n", total);
    fclose(fp);

    return 0;
}