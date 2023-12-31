#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check that a filename was passed as a command-line argument
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the input file for reading
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Get the size of the input file
    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        close(fd); // Close the file descriptor before returning
        return 1;
    }

    // Map the file to memory
    void *file_data = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_data == MAP_FAILED) {
        perror("mmap");
        close(fd); // Close the file descriptor before returning
        return 1;
    }

    // Read the file
    printf("File Contents:\n%s\n", (char *)file_data);

    // Unmap the file from memory
    if (munmap(file_data, sb.st_size) == -1) {
        perror("munmap");
        close(fd); // Close the file descriptor before returning
        return 1;
    }

    // Close the file descriptor
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}