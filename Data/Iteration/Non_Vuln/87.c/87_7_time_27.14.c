#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    int fd; // file descriptor

    // Open the file for reading
    fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    // Read the contents of the file
    char buffer[1024];
    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        // Process the data read from the file
        // TODO: Add your code here
    }

    if (bytesRead == -1) {
        perror("Error reading file");
        exit(1);
    }

    // Close the file
    close(fd);

    return 0;
}