List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `open()` at line 14, column 14 is not released after line 30, column 9.
 Example: 
  28.     char *addr = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, fd, 0);
  29.     if (addr == MAP_FAILED) {
  30.         perror("mmap");
              ^
  31.         return 1;
  32.     }

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
    off_t filesize = sb.st_size;
    char *addr = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }
    for (off_t i = 0; i < filesize; i++) {
        putchar(addr[i]);
    }
    if (munmap(addr, filesize) == -1) {
        perror("munmap");
        return 1;
    }
    return 0;
}