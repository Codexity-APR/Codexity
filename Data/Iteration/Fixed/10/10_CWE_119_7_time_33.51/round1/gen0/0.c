#include <stdio.h>
#include <stdlib.h>
#define MAX_FILENAME_LENGTH 100

int main()
{
    FILE *fp;
    char filename[MAX_FILENAME_LENGTH];
    int total = 0, num;
    
    printf("Enter filename: ");
    scanf("%99s", filename); // Limiting the input to 99 characters
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    while (fscanf(fp, "%d", &num) == 1) { // Checking the return value of fscanf
        total += num;
    }
    
    printf("Total: %d\n", total);
    fclose(fp);
    
    return 0;
}