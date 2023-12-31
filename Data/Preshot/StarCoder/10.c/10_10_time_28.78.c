#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main()
{
    FILE *fp;
    char filename[100], buffer[BUFFER_SIZE];
    int total = 0, num;

    printf("Enter filename: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0; // remove the newline character

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
    {
        if (sscanf(buffer, "%d", &num) == 1)
        {
            total += num;
        }
    }

    printf("Total: %d\n", total);

    fclose(fp);

    return 0;
}