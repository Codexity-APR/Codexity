#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[10];
    
    // Open the file for reading
    fp = fopen("example.txt", "r");
    
    // Move the file pointer to the 5th byte from the beginning of the file
    fseek(fp, 5, SEEK_SET);
    
    // Read and print the next 10 bytes from the file
    fread(buffer, 1, 10, fp);
    printf("%s\n", buffer);
    
    // Close the file
    fclose(fp);
    
    return 0;
}
