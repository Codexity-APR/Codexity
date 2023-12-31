#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/select.h>

#define FIFO_NAME "myfifo"

int main()
{
    int fd;
    char received_message[100];

    fd = open(FIFO_NAME, O_RDONLY | O_NONBLOCK);
    while (1) {
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(fd, &fds);
        FD_SET(STDIN_FILENO, &fds);

        // Wait for input on either the pipe or stdin
        if (select(fd + 1, &fds, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(1);
        }

        // Check if input is available on the pipe
        if (FD_ISSET(fd, &fds)) {
            ssize_t num_read = read(fd, received_message, sizeof(received_message));
            if (num_read < 0) {
                perror("read");
                exit(1);
            } else if (num_read == 0) {
                break;
            } else {
                printf("Receiver received message: %s\n", received_message);
            }
        }

        // Check if input is available on stdin
        if (FD_ISSET(STDIN_FILENO, &fds)) {
            char user_message[100];
            if (fgets(user_message, sizeof(user_message), stdin)) {
                if (write(fd, user_message, strlen(user_message)) < 0) {
                    perror("write");
                    exit(1);
                }
            } else {
                break;
            }
        }
    }

    close(fd);
    unlink(FIFO_NAME);

    return 0;
}