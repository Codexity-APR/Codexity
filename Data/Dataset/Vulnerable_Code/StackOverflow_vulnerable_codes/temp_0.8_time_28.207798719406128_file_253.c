#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // Check if the correct number of command line arguments is provided
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }
    
    // Open the file in read-only mode
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    
    // Define a buffer to read the file contents
    char buffer[1024];
    
    // Read the contents of the file and print them to stdout
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }
    
    // Check for read error
    if (bytesRead == -1) {
        perror("Error reading file");
        return 1;
    }
    
    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }
    
    return 0;
}