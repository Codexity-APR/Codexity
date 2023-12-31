#include <string.h>

int main(int argc, char* argv[]) {
    int fd;
    char* filename = argv[1];
    char* content = argv[2];
    int size = strlen(content);
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int flags = O_WRONLY | O_CREAT | O_TRUNC;
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
    return 0;
}