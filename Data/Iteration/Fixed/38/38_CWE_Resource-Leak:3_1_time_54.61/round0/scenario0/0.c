List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `open()` at line 14, column 14 is not released after line 36, column 9.
 Example: 
  34. 
  35.     if (munmap(file_data, file_size) == -1) {
  36.         perror("munmap");
              ^
  37.         return 1;
  38.     }

Error: Resource Leak   resource acquired by call to `open()` at line 14, column 14 is not released after line 29, column 9.
 Example: 
  27.     char *file_data = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
  28.     if (file_data == MAP_FAILED) {
  29.         perror("mmap");
              ^
  30.         return 1;
  31.     }

Error: Resource Leak   resource acquired by call to `open()` at line 14, column 14 is not released after line 22, column 9.
 Example: 
  20.     struct stat sb;
  21.     if (fstat(fd, &sb) == -1) {
  22.         perror("fstat");
              ^
  23.         return 1;
  24.     }


#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
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
        return 1;
    }
    off_t file_size = sb.st_size;
    char *file_data = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_data == MAP_FAILED) {
        perror("mmap");
        return 1;
    }
    // Perform operations on file_data
    if (munmap(file_data, file_size) == -1) {
        perror("munmap");
        return 1;
    }
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }
    return 0;
}