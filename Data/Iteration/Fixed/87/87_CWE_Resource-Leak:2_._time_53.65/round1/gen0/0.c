#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Open the file for reading
    int file_descriptor = open(argv[1], O_RDONLY);
    if (file_descriptor == -1) {
        perror("Failed to open the file");
        return 1;
    }

    // Read the content of the file and print it to the console
    char buffer[1024];
    ssize_t num_bytes_read;
    while ((num_bytes_read = read(file_descriptor, buffer, sizeof(buffer))) > 0) {
        if (write(STDOUT_FILENO, buffer, num_bytes_read) != num_bytes_read) {
            perror("Failed to write to stdout");
            close(file_descriptor); // Close the file before returning
            return 1;
        }
    }

    // Check for read error
    if (num_bytes_read == -1) {
        perror("Failed to read the file");
        close(file_descriptor); // Close the file before returning
        return 1;
    }

    // Close the file
    if (close(file_descriptor) == -1) {
        perror("Failed to close the file");
        return 1;
    }

    return 0;
}