#include <readline/readline.h>
#include <readline/history.h>
#else
#include <editline/readline.h>
#endif

#define FIFO_NAME "myfifo"

int main(void) {
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
#ifdef _GNU_SOURCE
            // Use GNU readline to get a line of input
            char *line = readline("Enter message: ");
#else
            // Use BSD readline to get a line of input
            char *line = readline("Enter message: ");
#endif
            if (line) {
                strncpy(user_message, line, sizeof(user_message));
                add_history(line);

                write(fd, user_message, strlen(user_message));
                printf("Sender sent message: %s\n", user_message);
            }
        }
    }

    return 0;
}