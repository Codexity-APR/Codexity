
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
        select(fd + 1, &fds, NULL, NULL, NULL);

        // Check if input is available on the pipe
        if (FD_ISSET(fd, &fds)) {
            read(fd, received_message, sizeof(received_message));
            printf("Receiver received message: %s\n", received_message);
        }

        // Check if input is available on stdin
        if (FD_ISSET(STDIN_FILENO, &fds)) {
            char user_message[100];
