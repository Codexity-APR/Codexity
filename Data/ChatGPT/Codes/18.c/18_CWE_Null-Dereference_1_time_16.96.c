#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[10];
    
    // Open the file for reading
    fp = fopen("example.txt", "r");
    
    // Move the file pointer to the 5th byte from the beginning of the file
    fseek(fp, 4, SEEK_SET);
    
    // Read 10 characters from the current position and store it in buffer
    fread(buffer, sizeof(char), 10, fp);
    
    // Close the file
    fclose(fp);
    
    // Print the buffer
    printf("%s\n", buffer);
    
    return 0;
}