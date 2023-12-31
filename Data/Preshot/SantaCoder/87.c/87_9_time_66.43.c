#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd;
    char buffer[1024];
    ssize_t num_read;

    if(argc != 2) {
        fprintf(stderr, "usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while((num_read = read(fd, buffer, 1024)) > 0) {
        if(write(STDOUT_FILENO, buffer, num_read) != num_read) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if(num_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    if(close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}