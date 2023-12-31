#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[10];

    // Open the file for reading
    fp = fopen("example.txt", "r");

    // Check if the file was opened successfully
    if (fp != NULL) {
        // Move the file pointer to the 5th byte from the beginning of the file
        fseek(fp, 4, SEEK_SET);

        // Read the contents of the file into the buffer
        fread(buffer, sizeof(char), 10, fp);

        // Print the buffer
        printf("Contents: %s\n", buffer);

        // Close the file
        fclose(fp);
    } else {
        printf("Failed to open the file.\n");
    }

    return 0;
}