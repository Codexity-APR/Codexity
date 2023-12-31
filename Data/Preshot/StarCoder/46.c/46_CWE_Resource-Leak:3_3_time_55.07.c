#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_LENGTH 1000
    
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
        perror("fstat");
        return 1;
    }
    size_t size = sb.st_size;
    
    // Check if the file is too large 
    if (size > MAX_LENGTH) {
        printf("File is too large, please provide a file smaller than %d\n", MAX_LENGTH);
        return 1;
    }

    // Create a memory-mapped file of the same size
    void *addr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Read the file contents
    char *contents = (char *)addr;
    for (size_t i = 0; i < size; i++) {
        contents[i] = getchar();
    }

    // Close the input file
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Write the file contents to stdout
    for (size_t i = 0; i < size; i++) {
        putchar(contents[i]);
    }

    // Unmap the memory-mapped file
    if (munmap(addr, size) == -1) {
        perror("munmap");
        return 1;
    }

    return 0;
}