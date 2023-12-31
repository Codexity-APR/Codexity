#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd, ret;
    char buf[1024];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    ret = read(fd, buf, sizeof(buf));
    if (ret == -1) {
        perror("read");
        exit(1);
    }

    ret = write(STDOUT_FILENO, buf, ret);
    if (ret == -1) {
        perror("write");
        exit(1);
    }

    close(fd);
    return 0;
}