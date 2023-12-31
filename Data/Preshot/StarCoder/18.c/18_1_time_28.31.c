#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    char buffer[10];
    
    // Open the file for reading
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("File open failed");
        exit(EXIT_FAILURE);
    }
    
    // Move the file pointer to the 5th byte from the beginning of the file
    if (fseek(fp, 5, SEEK_SET) != 0) {
        perror("File seek failed");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    
    // Read the first 10 bytes from the file
    if (fread(buffer, 1, 10, fp) != 10) {
        perror("File read failed");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    
    // Print the contents of the buffer
    printf("%s\n", buffer);
    
    // Close the file
    fclose(fp);
    
    return 0;
}