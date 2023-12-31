#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    FILE *fp;
    char filename[100];
    int total = 0, num;

    printf("Enter filename: ");
    if(scanf("%99s", filename) != 1){
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(filename, "w");
    if(fp == NULL){
        printf("Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter number of lines: ");
    if(scanf("%d", &num) != 1){
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num; i++)
    {
        int c = getchar();
        while(c != '\n' && c != EOF){
            total++;
            fputc(c, fp); // write character to the file
            c = getchar();
        }
        fputc('\n', fp); // write new line character to the file
        total++; // increment for new line character
    }

    printf("Total lines: %d\n", total);
    fclose(fp);

    return 0;
}