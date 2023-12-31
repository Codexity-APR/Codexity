#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }
    
    char* file_name = argv[1];
    int file_descriptor;

    // Open the file in read-only mode
    file_descriptor = open(file_name, O_RDONLY);
    if (file_descriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read the content of the file and print it to the console
    char buffer[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(file_descriptor, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    // Close the file
    if (close(file_descriptor) == -1) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}