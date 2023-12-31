#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
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

    void *addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    close(fd);

    char *new_addr = malloc(sb.st_size);
    if (new_addr == NULL) {
        perror("malloc");
        return 1;
    }

    memcpy(new_addr, addr, sb.st_size);

    if (munmap(addr, sb.st_size) == -1) {
        perror("munmap");
        free(new_addr);
        return 1;
    }

    int fd_new = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_new == -1) {
        perror("open");
        free(new_addr);
        return 1;
    }

    if (write(fd_new, new_addr, sb.st_size)!= sb.st_size) {
        perror("write");
        free(new_addr);
        close(fd_new);
        return 1;
    }

    if (close(fd_new) == -1) {
        perror("close");
        free(new_addr);
        return 1;
    }

    free(new_addr);

    return 0;
}