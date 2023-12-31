#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[10];

    // Open the file for reading
    fp = fopen("example.txt", "r");

    // Check if the file was opened successfully
    if (fp != NULL) {
        // Move the file pointer to the 5th byte from the beginning of the file
        fseek(fp, 5, SEEK_SET);

        // Read and display the contents from the file
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }

        // Close the file
        fclose(fp);
    } else {
        printf("Failed to open the file.\n");
    }

    return 0;
}