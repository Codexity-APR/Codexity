#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd;
    char buffer[1024];
    ssize_t bytesRead;

    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        if (write(STDOUT_FILENO, buffer, bytesRead) != bytesRead) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if (bytesRead == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}