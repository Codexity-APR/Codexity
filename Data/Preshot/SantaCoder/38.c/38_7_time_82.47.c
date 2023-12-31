#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>

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

    char *mapped = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapped == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    close(fd);

    char *copy = malloc(sb.st_size);
    if (copy == NULL) {
        perror("malloc");
        munmap(mapped, sb.st_size);
        return 1;
    }

    memcpy(copy, mapped, sb.st_size);

    printf("Copy of the file: %s\n", copy);

    munmap(mapped, sb.st_size);
    free(copy);

    return 0;
}