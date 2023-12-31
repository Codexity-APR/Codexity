#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fileDescriptor;
    char buffer[100];
    
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    fileDescriptor = open(argv[1], O_RDONLY);
    if (fileDescriptor == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    ssize_t bytesRead = read(fileDescriptor, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }
    
    printf("File contents: \n");
    write(STDOUT_FILENO, buffer, bytesRead);
    
    close(fileDescriptor);
    
    return 0;
}