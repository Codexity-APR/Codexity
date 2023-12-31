#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int fd;
    char* filename = argv[1];
    char* content = argv[2];
    int size = atoi(argv[3]);
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int flags = O_CREAT | O_WRONLY | O_TRUNC;
    int ret;

    fd = open(filename, flags, mode);
    if (fd == -1) {
        fprintf(stderr, "Cannot open file %s: %s\n", filename, strerror(errno));
        exit(1);
    }

    ret = write(fd, content, size);
    if (ret == -1) {
        fprintf(stderr, "Cannot write to file %s: %s\n", filename, strerror(errno));
        exit(1);
    }

    close(fd);
    return 0;
}