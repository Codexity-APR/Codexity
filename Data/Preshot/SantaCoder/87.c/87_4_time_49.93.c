#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd;
    char *filename = "example.txt";
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // file permissions

    // create a new file or truncate an existing one
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // write data to the file
    const char *data = "Hello, world!\n";
    ssize_t bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // close the file
    close(fd);

    return 0;
}