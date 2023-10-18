#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, c;
    struct sockaddr_in server, client;
    char message[2000], server_reply[2000];

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
        return 1;
    }
    printf("bind done");

    // Listen
    listen(socket_desc, 3);

    // Accept incoming connection
    printf("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if (client_sock < 0) {
        perror("accept failed");
        return 1;
    }
    printf("Connection accepted");

    // Receive a message from client
    if (recv(client_sock, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("Reply received: %s", server_reply);

    // Send a reply to the client
    strcpy(message, "Server reply: Received your message");
    if (send(client_sock, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }
    printf("Reply sent");

    close(client_sock);
    close(socket_desc);

    return 0;
}