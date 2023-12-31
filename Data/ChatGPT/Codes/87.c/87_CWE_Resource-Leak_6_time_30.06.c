#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd;
    
    if (argc != 2) {
        printf("Usage: ./program_name <filename>\n");
        return 1;
    }
    
    // Open the file for reading
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Unable to open file");
        return 1;
    }
    
    // Read from the file and print its content
    char buffer[1024];
    ssize_t bytesRead;
    
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }
    
    if (bytesRead == -1) {
        perror("Error reading from file");
        return 1;
    }
    
    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }
    
    return 0;
}