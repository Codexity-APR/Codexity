#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Read file content and print it out
    const int BUFF_SIZE = 1024;
    char buffer[BUFF_SIZE];
    ssize_t bytes_read = 0;
    while ((bytes_read = read(fd, buffer, BUFF_SIZE)) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    close(fd);
    return 0;
}