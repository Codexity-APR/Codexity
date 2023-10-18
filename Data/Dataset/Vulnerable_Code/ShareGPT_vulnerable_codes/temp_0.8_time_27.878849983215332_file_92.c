#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[10];
    
    // Open the file for reading
    fp = fopen("example.txt", "r");
    
    // Move the file pointer to the 5th byte from the beginning of the file
    fseek(fp, 4, SEEK_SET);
    
    // Read the content from the file into the buffer
    fread(buffer, sizeof(char), 9, fp);
    buffer[9] = '\0'; // Null-terminate the buffer
    
    // Print the content of the buffer
    printf("Content: %s\n", buffer);
    
    // Close the file
    fclose(fp);
    
    return 0;
}