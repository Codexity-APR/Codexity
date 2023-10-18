#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd;
    char buffer[100];

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Open the file
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read the contents of the file and print them
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        perror("Error reading file");
        return 1;
    }

    printf("File contents:\n");
    write(STDOUT_FILENO, buffer, bytesRead);

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}