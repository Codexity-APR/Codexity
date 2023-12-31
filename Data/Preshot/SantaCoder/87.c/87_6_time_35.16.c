#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // Set file permissions
    fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, mode); // Open file
    if(fd == -1) { // Check if file was opened successfully
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    // Write to file
    if(write(fd, "Hello World!", 12) == -1) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }
    close(fd); // Close file
    return 0;
}