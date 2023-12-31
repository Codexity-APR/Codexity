#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // Check if the correct number of command-line arguments were given
    if (argc != 2) {
        printf("Error: Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the file for reading
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read contents of the file
    char buffer[1024];
    ssize_t num_bytes_read;
    while ((num_bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        // Write contents to standard output
        write(STDOUT_FILENO, buffer, num_bytes_read);
    }

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}