#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    
    // Open the file for reading
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }
    
    // Read and print the content of the file
    char buffer[1024];
    ssize_t bytesRead;
    
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }
    
    // Close the file
    close(fd);
    
    return 0;
}