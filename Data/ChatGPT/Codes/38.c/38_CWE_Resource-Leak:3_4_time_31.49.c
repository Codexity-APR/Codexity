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
    char *filedata = mmap(NULL, filesize, PROT_READ, MAP_SHARED, fd, 0);
    if (filedata == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    for (off_t i = 0; i < filesize; i++) {
        putchar(filedata[i]);
    }

    if (munmap(filedata, filesize) == -1) {
        perror("munmap");
        return 1;
    }

    close(fd);

    return 0;
}