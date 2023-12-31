#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // Check if the correct number of command line arguments are provided
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    // Open the file in read-only mode
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    // Read the contents of the file and print them to stdout
    char buffer[1024];
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    // Close the file
    if (close(fd) == -1) {
        perror("Failed to close file");
        return 1;
    }

    return 0;
}