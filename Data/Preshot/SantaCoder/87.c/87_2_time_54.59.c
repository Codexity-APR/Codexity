#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // set file permissions
    char* filename = "example.txt"; // specify filename
    char* buffer = "Hello, world!"; // specify content to write to file
    
    // attempt to open file
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    // write content to file
    if (write(fd, buffer, strlen(buffer)) != strlen(buffer)) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    
    // close file
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    
    printf("Successfully wrote to file %s\n", filename);
    return 0;
}