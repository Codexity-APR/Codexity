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
        close(fd);
        return 1;
    }

    void *addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    close(fd);

    int out_fd = open("output.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (out_fd == -1) {
        perror("open");
        munmap(addr, sb.st_size);
        return 1;
    }

    if (write(out_fd, addr, sb.st_size) == -1) {
        perror("write");
        munmap(addr, sb.st_size);
        close(out_fd);
        return 1;
    }

    if (munmap(addr, sb.st_size) == -1) {
        perror("munmap");
        close(out_fd);
        return 1;
    }

    close(out_fd);

    return 0;
}