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
        select(fd + 1, &fds, NULL, NULL, NULL);

        // Check if input is available on the pipe
        if (FD_ISSET(fd, &fds)) {
            ssize_t bytes_read = read(fd, received_message, sizeof(received_message));
            if (bytes_read == -1) {
                perror("Error reading from FIFO");
                exit(1);
            } else if (bytes_read == 0) {
                // No data available
                continue;
            } else {
                printf("Receiver received message: %s\n", received_message);
            }
        }

        // Check if input is available on stdin
        if (FD_ISSET(STDIN_FILENO, &fds)) {
            char user_message[100];
            if (fgets(user_message, sizeof(user_message), stdin) == NULL) {
                // End of file reached (e.g. Ctrl-D on Unix)
                printf("End of file reached, exiting.\n");
                exit(0);
            } else {
                // Remove newline character from user message
                user_message[strcspn(user_message, "\n")] = '\0';

                // Write user message to the pipe
                ssize_t bytes_written = write(fd, user_message, strlen(user_message));
                if (bytes_written == -1) {
                    perror("Error writing to FIFO");
                    exit(1);
                } else if (bytes_written == 0) {
                    printf("No bytes written to FIFO\n");
                } else {
                    printf("Sender sent message: %s\n", user_message);
                }
            }
        }
    }

    close(fd);
    return 0;
}