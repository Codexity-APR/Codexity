#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[10];
    
    // Open the file for reading
    fp = fopen("example.txt", "r");
    
    // Move the file pointer to the 5th byte from the beginning of the file
    fseek(fp, 4, SEEK_SET);
    
    // Read 10 bytes from the current position of the file pointer
    fread(buffer, sizeof(char), 10, fp);
    
    // Print the contents of the buffer
    printf("Buffer: %s\n", buffer);
    
    // Close the file
    fclose(fp);
    
    return 0;
}