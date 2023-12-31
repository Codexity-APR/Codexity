#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: mmapcopy <filename>\n");
        return 1;
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        return 1;
    }

    void *addr = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    char *new_addr = malloc(sb.st_size);
    if (new_addr == NULL) {
        perror("malloc");
        return 1;
    }

    memcpy(new_addr, addr, sb.st_size);

    if (munmap(addr, sb.st_size) == -1) {
        perror("munmap");
        return 1;
    }

    close(fd);

    fd = open(filename, O_WRONLY | O_TRUNC);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (write(fd, new_addr, sb.st_size) != sb.st_size) {
        perror("write");
        return 1;
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    free(new_addr);

    return 0;
}