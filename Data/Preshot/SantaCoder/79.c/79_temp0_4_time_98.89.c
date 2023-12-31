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
    if (fd == -1) {
        perror("Error opening FIFO");
        exit(1);
    }

    while (1) {
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(fd, &fds);
        FD_SET(STDIN_FILENO, &fds);

        // Wait for input on either the pipe or stdin
        if (select(fd + 1, &fds, NULL, NULL, NULL) == -1) {
            perror("Error in select");
            exit(1);
        }

        // Check if input is available on the pipe
        if (FD_ISSET(fd, &fds)) {
            ssize_t bytes_read = read(fd, received_message, sizeof(received_message));
            if (bytes_read == -1) {
                perror("Error reading from FIFO");
                exit(1);
            } else if (bytes_read == 0) {
                printf("FIFO closed\n");
                exit(0);
            } else {
                printf("Receiver received message: %s\n", received_message);
            }
        }

        // Check if input is available on stdin
        if (FD_ISSET(STDIN_FILENO, &fds)) {
            char user_message[100];
            if (fgets(user_message, sizeof(user_message), stdin) == NULL) {
                perror("Error reading from stdin");
                exit(1);
            } else {
                printf("Sender sent message: %s", user_message);
            }
        }
    }

    close(fd);
    return 0;
}