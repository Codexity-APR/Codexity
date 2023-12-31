#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int socket_desc, new_socket, c;
    struct sockaddr_in server, client;
    char *message;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed. Error");
        close(socket_desc); // Close the socket before returning
        return 1;
    }

    printf("Bind done\n");

    // Listen
    listen(socket_desc, 3);

    // Accept incoming connection
    printf("Waiting for incoming connections...\n");
    c = sizeof(struct sockaddr_in);
    new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if (new_socket < 0) {
        perror("accept failed");
        close(socket_desc); // Close the socket before returning
        return 1;
    }

    printf("Connection accepted\n");

    // Reply to the client
    message = "Hello from server!\n";
    write(new_socket, message, strlen(message));

    // Close the socket before returning
    close(socket_desc);
    return 0;
}