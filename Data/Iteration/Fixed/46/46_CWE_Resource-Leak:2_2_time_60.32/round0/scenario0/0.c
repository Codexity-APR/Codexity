List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `open()` at line 15, column 14 is not released after line 31, column 9.
 Example: 
  29.     void *addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  30.     if (addr == MAP_FAILED) {
  31.         perror("mmap");
              ^
  32.         return 1;
  33.     }

Error: Resource Leak   resource acquired by call to `open()` at line 15, column 14 is not released after line 24, column 9.
 Example: 
  22.     struct stat sb;
  23.     if (fstat(fd, &sb) == -1) {
  24.         perror("fstat");
              ^
  25.         return 1;
  26.     }


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
        perror("fstat");
        return 1;
    }
    // Map the input file into memory
    void *addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }
    // Close the input file
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }
    // Process the file
    // (Add your code here)
    // Unmap the file from memory
    if (munmap(addr, sb.st_size) == -1) {
        perror("munmap");
        return 1;
    }
    return 0;
}