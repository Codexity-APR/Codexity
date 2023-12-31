#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_LINES 1000

int main()
{
    FILE *fp;
    char filename[MAX_FILENAME_LENGTH];
    int total = 0, num;

    printf("Enter filename: ");
    if (scanf("%99s", filename) != 1) {
      printf("Invalid input\n");
      return 1;
    }

    fp = fopen(filename, "w");
    if (fp == NULL) {
      printf("Failed to open file\n");
      return 1;
    }

    printf("Enter number of lines (max %d): ", MAX_LINES);
    if (scanf("%d", &num) != 1) {
      printf("Invalid input\n");
      return 1;
    }

    if (num <= 0 || num > MAX_LINES) {
      printf("Invalid number of lines\n");
      return 1;
    }

    for (int i = 0; i < num; i++) {
        char line[100];
        printf("Enter line %d: ", i+1);
        if (scanf("%99s", line) != 1) {
          printf("Invalid input\n");
          return 1;
        }
        fprintf(fp, "%s\n", line);
        total++;
    }

    printf("\n");
    printf("Total lines: %d\n", total);
    fclose(fp);

    return 0;
}