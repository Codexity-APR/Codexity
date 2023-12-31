#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file in read-only mode
    int file_descriptor = open(argv[1], O_RDONLY);
    if (file_descriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read the contents of the file and print them to the console
    char buffer[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(file_descriptor, buffer, sizeof(buffer))) > 0) {
        ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
        if (bytes_written == -1) {
            perror("Error writing to stdout");
            close(file_descriptor);
            return 1;
        }
    }

    // Check for errors during the read operation
    if (bytes_read == -1) {
        perror("Error reading file");
        close(file_descriptor);
        return 1;
    }

    // Close the file
    close(file_descriptor);

    return 0;
}