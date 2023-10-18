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

    mkfifo(FIFO_NAME, 0666);

    fd = open(FIFO_NAME, O_RDONLY | O_NONBLOCK);
    while (1) {
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(fd, &fds);
        FD_SET(STDIN_FILENO, &fds);

        // Wait for input on either the pipe or stdin
        select(fd + 1, &fds, NULL, NULL, NULL);

        // Check if input is available on the pipe
        if (FD_ISSET(fd, &fds)) {
            read(fd, received_message, sizeof(received_message));
            printf("Receiver received message: %s\n", received_message);
        }

        // Check if input is available on stdin
        if (FD_ISSET(STDIN_FILENO, &fds)) {
            char user_message[100];
            fgets(user_message, sizeof(user_message), stdin);
            int len = strlen(user_message);

            // Remove trailing newline character
            if (user_message[len - 1] == '\n') {
                user_message[len - 1] = '\0';
            }

            // Write user message to the pipe
            int write_fd = open(FIFO_NAME, O_WRONLY);
            write(write_fd, user_message, strlen(user_message));
            close(write_fd);
        }
    }

    close(fd);
    unlink(FIFO_NAME);

    return 0;
}