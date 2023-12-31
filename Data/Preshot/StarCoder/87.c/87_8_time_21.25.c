#include <string.h>
#include <errno.h>

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
        fprintf(stderr, "Failed to open %s: %s\n", filename, strerror(errno));
        exit(1);
    }

    ret = write(fd, content, size);
    if (ret == -1) {
        fprintf(stderr, "Failed to write to %s: %s\n", filename, strerror(errno));
        exit(1);
    }

    close(fd);
    return 0;
}