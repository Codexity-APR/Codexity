#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[10];

    // Open the file for reading
    fp = fopen("example.txt", "r");

    // Move the file pointer to the 5th byte from the beginning of the file
    fseek(fp, 4, SEEK_SET);

    // Read and print the contents of the file from the current position
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(fp);

    return 0;
}