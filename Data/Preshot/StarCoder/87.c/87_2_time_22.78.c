#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int fd;
    char* filename = argv[1];
    char* content = argv[2];
    int size = atoi(argv[3]);
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // file permissions
    int flags = O_CREAT | O_WRONLY; // create the file if it doesn't exist and write-only mode
    int ret; // return value for write system call

    fd = open(filename, flags, mode);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    ret = write(fd, content, size);
    if (ret == -1) {
        perror("write");
        exit(1);
    }

    close(fd);
    return 0;
}