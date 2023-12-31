#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: mmapcopy <filename>\n");
        return 1;
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
	close(fd);
	return 1;
    }

    void *mapped = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapped == MAP_FAILED) {
        perror("mmap");
	close(fd);
	return 1;
    }
    
    int out_fd = open("output.dat", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (out_fd == -1) {
	perror("open");
	close(fd);
        return 1;
    }
    
    if (write(out_fd, mapped, sb.st_size) != sb.st_size) {
	perror("write");
	close(fd);
	close(out_fd);
	munmap(mapped, sb.st_size);
	return 1;
    }

    if (munmap(mapped, sb.st_size) == -1) {
	perror("munmap");
	close(fd);
	close(out_fd);
	return 1;
    }

    if (close(fd) == -1) {
        perror("close input");
	close(out_fd);
	return 1;
    }

    if (close(out_fd) == -1) {
        perror("close output");
	return 1;
    }

    return 0;
}