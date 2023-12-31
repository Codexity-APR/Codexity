#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[10];

    // Open the file for reading
    fp = fopen("example.txt", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Move the file pointer to the 5th byte from the beginning of the file
    fseek(fp, 4, SEEK_SET);

    // Read 10 characters from the file into the buffer
    fread(buffer, sizeof(char), 10, fp);

    // Close the file
    fclose(fp);

    // Print the contents of the buffer
    printf("Contents of buffer: %s\n", buffer);

    return 0;
}