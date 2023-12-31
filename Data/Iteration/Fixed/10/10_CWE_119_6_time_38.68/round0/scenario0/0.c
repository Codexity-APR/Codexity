List of vulnerabilities detected: 
 Error type: CWE-119 at line: 11. Error message: scanf() without field width limits can crash with huge input data.


#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    char filename[100];
    int total = 0, num;
    printf("Enter filename: ");
    scanf("%s", filename);
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