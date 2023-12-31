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
        close(fd); // Close the file descriptor before returning
        return 1;
    }
    off_t file_size = sb.st_size;
    char *file_memory = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_memory == MAP_FAILED) {
        perror("mmap");
        close(fd); // Close the file descriptor before returning
        return 1;
    }
    close(fd); // Close the file descriptor after mmap
    // Add your code here
    munmap(file_memory, file_size);
    return 0;
}