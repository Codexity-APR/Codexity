#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int result = 0;
    if (argc != 2) {
        printf("Usage: mmapcopy <filename>\n");
        result = 1;
        goto cleanup;
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        result = 1;
        goto cleanup;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        result = 1;
        goto cleanup;
    }

    if (mmap(fd, &sb, MAP_SHARED, PROT_READ, 0, 0) == -1) {
        perror("mmap");
        result = 1;
        goto cleanup;
    }

    if (mmap(fd, &sb, MAP_PRIVATE, PROT_READ, 0, 0) == -1) {
        perror("mmap");
        result = 1;
        goto cleanup;
    }

    if (mmap(fd, &sb, MAP_ANONYMOUS, PROT_READ, 0, 0) == -1) {
        perror("mmap");
        result = 1;
        goto cleanup;
    }

    if (mmap(fd, &sb, MAP_PRIVATE, PROT_WRITE, 0, 0) == -1) {
        perror("mmap");
        result = 1;
        goto cleanup;
    }

    if (mmap(fd, &sb, MAP_ANONYMOUS, PROT_WRITE, 0, 0) == -1) {
        perror("mmap");
        result = 1;
        goto cleanup;
    }

    if (mmap(fd, &sb, MAP_PRIVATE, PROT_EXEC, 0, 0) == -1) {
        perror("mmap");
        result = 1;
        goto cleanup;
    }

    if (mmap(fd, &sb, MAP_ANONYMOUS, PROT_EXEC, 0, 0) == -1) {
        perror("mmap");
        result = 1;
        goto cleanup;
    }

    if (mmap(fd, &sb, MAP_PRIVATE, PROT_EXEC, 0, 0) == -1) {
        perror("mmap");
        result = 1;
        goto cleanup;
    }

    if (mmap(fd, &sb, MAP_ANONYMOUS, PROT_EXEC, 0, 0) == -1) {
        perror("mmap");
        result = 1;
        goto cleanup;
    }

    if (mmap(fd, &sb, MAP_PRIVATE, PROT_EXEC, 0, 0) == -1) {
        perror("mmap");
        result = 1;
        goto cleanup;
    }

    if (mmap(fd, &sb, MAP_ANONYMOUS, PROT_EXEC, 0, 0) == -1) {
        perror("mmap");
        result = 1;
        goto cleanup;
    }