#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd;
    char* filename = argv[1];
    char* content = argv[2];
    int size = atoi(argv[3]);
    int mode = atoi(argv[4]);
    int flags = atoi(argv[5]);
    int ret;

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

    printf("File '%s' has been written with content '%s'\n", filename, content);

    return 0;
}