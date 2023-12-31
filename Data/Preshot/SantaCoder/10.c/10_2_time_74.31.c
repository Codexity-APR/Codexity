#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME_SIZE 100

int main()
{
    FILE *fp;
    char filename[MAX_FILE_NAME_SIZE];
    int total = 0, num;

    printf("Enter filename: ");
    if (fgets(filename, MAX_FILE_NAME_SIZE, stdin) == NULL) {
        perror("Error reading the filename.");
        exit(EXIT_FAILURE);
    }
    filename[strcspn(filename, "\n")] = '\0'; // remove the newline character at the end of the filename

    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening the file.");
        exit(EXIT_FAILURE);
    }

    printf("Enter number of lines: ");
    if (scanf("%d", &num) != 1) {
        perror("Error reading the number of lines.");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num; i++)
    {
        printf("Enter line %d: ", i + 1);
        char line[MAX_FILE_NAME_SIZE];
        if (fgets(line, MAX_FILE_NAME_SIZE, stdin) == NULL) {
            perror("Error reading the line.");
            exit(EXIT_FAILURE);
        }
        fprintf(fp, "%s", line);
        total++;
    }

    printf("\nTotal lines written to file: %d\n", total);
    fclose(fp);

    return 0;
}