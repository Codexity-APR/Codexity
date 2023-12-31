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

    off_t file_size = sb.st_size;
    char *file_data = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_data == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Perform operations on file_data

    if (munmap(file_data, file_size) == -1) {
        perror("munmap");
        return 1;
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}