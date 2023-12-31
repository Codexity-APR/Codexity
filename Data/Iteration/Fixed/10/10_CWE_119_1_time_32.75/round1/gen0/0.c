#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[100];
    int total = 0, num;
    
    printf("Enter filename: ");
    scanf("%99s", filename); // Added field width limit of 99
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    while (fscanf(fp, "%d", &num) == 1) {
        total += num;
    }
    
    fclose(fp);
    
    printf("Total: %d\n", total);
    
    return 0;
}