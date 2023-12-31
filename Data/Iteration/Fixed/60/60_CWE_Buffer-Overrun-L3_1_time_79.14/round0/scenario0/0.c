List of vulnerabilities detected: 
Error: Buffer Overrun L3   Offset: [-1, 98] Size: 100.
 Example: 
  40. 
  41.             // Remove newline character from user input
  42.             if (user_message[len - 1] == '\n') {
                      ^
  43.                 user_message[len - 1] = '\0';
  44.             }


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
    // Create the named pipe if it doesn't exist
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
            // Remove newline character from user input
            if (user_message[len - 1] == '\n') {
                user_message[len - 1] = '\0';
            }
            // Display user input
            printf("Sender sent message: %s\n", user_message);
            // Open the named pipe for writing
            int fd_write = open(FIFO_NAME, O_WRONLY);
            // Write user input to the pipe
            write(fd_write, user_message, strlen(user_message) + 1);
            // Close the write file descriptor
            close(fd_write);
        }
    }
    // Close the read file descriptor
    close(fd);
    // Remove the named pipe
    remove(FIFO_NAME);
    return 0;
}