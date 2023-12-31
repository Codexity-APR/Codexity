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
    fd_set fds;

    fd = open(FIFO_NAME, O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        printf("Error opening FIFO\n");
        return 1;
    }

    while (1) {
        FD_ZERO(&fds);
        FD_SET(fd, &fds);
        FD_SET(STDIN_FILENO, &fds);

        // Wait for input on either the pipe or stdin
        select(fd + 1, &fds, NULL, NULL, NULL);

        // Check if input is available on the pipe
        if (FD_ISSET(fd, &fds)) {
            ssize_t bytes_read = read(fd, received_message, sizeof(received_message));
            if (bytes_read > 0) {
                printf("Receiver received message: %.*s\n", (int)bytes_read, received_message);
            }
        }

        // Check if input is available on stdin
        if (FD_ISSET(STDIN_FILENO, &fds)) {
            char user_message[100];
            if (fgets(user_message, sizeof(user_message), stdin)) {
                int len = strlen(user_message);
                if (len > 0 && user_message[len - 1] == '\n') {
                    user_message[len - 1] = '\0';
                }
                printf("Sender sending message: %s\n", user_message);
            }
        }
    }

    close(fd);
    return 0;
}