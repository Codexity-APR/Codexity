#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[100];
    int total = 0, num;

    printf("Enter filename: ");
    scanf("%99s", filename); // Added field width limit of 99 for filename

    // Open the file
    fp = fopen(filename, "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read numbers from the file and calculate the total
    while (fscanf(fp, "%d", &num) == 1) {
        total += num;
    }

    // Close the file
    fclose(fp);

    printf("The total is: %d\n", total);

    return 0;
}