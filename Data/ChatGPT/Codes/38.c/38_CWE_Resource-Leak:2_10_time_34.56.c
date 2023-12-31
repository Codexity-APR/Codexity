#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: mmapcopy <filename>\n");
        return 1;
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        return 1;
    }

    off_t filesize = sb.st_size;

    char *addr = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    for (off_t i = 0; i < filesize; i++) {
        putchar(addr[i]);
    }

    if (munmap(addr, filesize) == -1) {
        perror("munmap");
        return 1;
    }

    return 0;
}