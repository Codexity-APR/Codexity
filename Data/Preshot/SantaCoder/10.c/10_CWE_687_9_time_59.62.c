#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LEN 100

int main()
{
    FILE *fp;
    char filename[MAX_FILENAME_LEN + 1]; // add 1 for null terminator
    int total = 0, num;

    printf("Enter filename: ");
	scanf("%100s", filename); // limit input to 100 characters
    
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    printf("Enter number of lines: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Enter line %d: ", i+1);
        char line[100];
        scanf("%100s", line); // limit input to 100 characters
        fprintf(fp, "%s\n", line);
        total++;
    }

    printf("\n");
    printf("Total lines: %d\n", total);
    fclose(fp);

    return 0;
}