#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[10];
    
    // Open the file for reading
    fp = fopen("example.txt", "r");
    
    // Move the file pointer to the 5th byte from the beginning of the file
    fseek(fp, 4, SEEK_SET);
    
    // Read 10 characters from the file into the buffer
    fread(buffer, sizeof(char), 10, fp);
    
    // Close the file
    fclose(fp);
    
    // Print the contents of the buffer
    printf("Contents of the buffer: %s\n", buffer);
    
    return 0;
}