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
        return 1;
    }

    // Map the input file into memory
    char *input = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (input == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Print the contents of the input file
    printf("%.*s", (int) sb.st_size, input);

    // Unmap the input file from memory
    if (munmap(input, sb.st_size) == -1) {
        perror("munmap");
        return 1;
    }

    // Close the input file
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}
