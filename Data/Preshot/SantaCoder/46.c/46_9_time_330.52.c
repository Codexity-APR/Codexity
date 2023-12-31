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
	perror("stat");
        return 1;
    }

    // Get the size of the output file
    int ofd = open(argv[2], O_WRONLY);
    if (ofd == -1) {
        perror("open");
        return 1;
    }

    // Get the size of the output file
    int ofs = fstat(ofd).st_size;

    // Allocate the output file
    if (fallocate(ofd, ofs, F_SETSIZE) == -1) {
        perror("fallocate");
        return 1;
    }

    // Read the input file
    if (fread(fd, &sb, ofs) == -1) {
        perror("fread");
        return 1;
    }

    // Write the output file
    if (fwrite(ofd, &sb, ofs) == -1) {
        perror("fwrite");
        return 1;
    }

    // Close the input file
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Close the output file
    if (close(ofd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(ofd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(ofd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(ofd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(ofd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(ofd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(ofd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(ofd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(ofd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(ofd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(ofd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(ofd) == -1) {
        perror("close");
        return 1;
    }

    // Close the file descriptors
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }}