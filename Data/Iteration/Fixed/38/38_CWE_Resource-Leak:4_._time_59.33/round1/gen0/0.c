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
        close(fd); // Release the resource before returning
        return 1;
    }

    off_t file_size = sb.st_size;
    char *file_contents = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_contents == MAP_FAILED) {
        perror("mmap");
        close(fd); // Release the resource before returning
        return 1;
    }

    ssize_t bytes_written = write(STDOUT_FILENO, file_contents, file_size);
    if (bytes_written != file_size) {
        perror("write");
        munmap(file_contents, file_size); // Release the resource before returning
        close(fd); // Release the resource before returning
        return 1;
    }

    if (munmap(file_contents, file_size) == -1) {
        perror("munmap");
        close(fd); // Release the resource before returning
        return 1;
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}