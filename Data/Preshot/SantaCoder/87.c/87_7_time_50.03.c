#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    int fd, n;
    char buf[1024];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    while ((n = read(fd, buf, 1024)) > 0) {
        write(STDOUT_FILENO, buf, n);
    }

    close(fd);

    return 0;
}