#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	int fd;
	char* filename = argv[1];
	char* content = argv[2];
	int size = atoi(argv[3]);
	int mode = atoi(argv[4]);
	int flags = atoi(argv[5]);
	int ret;

	fd = open(filename, flags, mode);
	if (fd == -1) {
		perror("open");
		exit(1);
	}

	ret = write(fd, content, size);
	if (ret == -1) {
		perror("write");
		exit(1);
	}

	close(fd);
	return 0;
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    int fd;
    char* filename = argv[1];
    char* buffer = malloc(sizeof(char) * atoi(argv[2]));
    int size = atoi(argv[2]);
    int mode = S_IRUSR | S_IWUSR;
    int flags = O_RDWR;
    int ret;

    fd = open(filename, flags, mode);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    ret = read(fd, buffer, size);
    if (ret == -1) {
        perror("read");
        exit(1);
    }

    printf("%s\n", buffer);

    close(fd);
    return 0;
}