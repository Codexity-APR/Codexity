#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd; // file descriptor

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Read from the file
    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    // Print the contents of the file
    printf("File contents:\n");
    write(STDOUT_FILENO, buffer, bytesRead);

    // Close the file
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}