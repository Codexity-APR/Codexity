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
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }
    while (fscanf(fp, "%d", &num) != EOF)
    {
        total += num;
    }
    printf("Total sum: %d\n", total);
    fclose(fp);
    return 0;
}