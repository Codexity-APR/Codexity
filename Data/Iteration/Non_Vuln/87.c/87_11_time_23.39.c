#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    // Open the file in read-only mode
    int file_descriptor = open(argv[1], O_RDONLY);
    if (file_descriptor == -1) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the content of the file and display it
    char buffer[100];
    ssize_t bytes_read;
    while ((bytes_read = read(file_descriptor, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    // Close the file
    close(file_descriptor);

    return 0;
}