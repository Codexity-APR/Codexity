#include <stdio.h>

int main()
{
    FILE *fp;
    char buffer[10];
    
    // Open the file for reading
    fp = fopen("example.txt", "r");
    
    // Move the file pointer to the 5th byte from the beginning of the file
	// and read 10 bytes from the file.
    fp.seek(5);
    buffer[0] = fp.read(10);
    
    // Close the file
    fp.close();
    
    // Print the buffer
    for (int i = 0; i < 10; i++)
        printf("%c", buffer[i]);
    
    return 0;
}