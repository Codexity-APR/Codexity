#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd, numBytes;
    char buffer[1024];

    if(argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);

    if(fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    while((numBytes = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, numBytes);
    }

    close(fd);

    return 0;
}