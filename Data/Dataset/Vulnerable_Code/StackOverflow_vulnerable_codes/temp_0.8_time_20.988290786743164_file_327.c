#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int file_descriptor;
    char buffer[100];
    ssize_t bytes_read;

    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    file_descriptor = open(argv[1], O_RDONLY);
    if (file_descriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    while ((bytes_read = read(file_descriptor, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    if (bytes_read == -1) {
        perror("Error reading file");
        return 1;
    }

    close(file_descriptor);

    return 0;
}