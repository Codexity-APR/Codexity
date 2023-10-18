#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 1025
#define IP "172.22.100.100"

int main()
{
    int socket_id;
    struct sockaddr_in server_address;

    // Create socket
    socket_id = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_id == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(IP);

    // Connect to the server
    if (connect(socket_id, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Failed to connect to server\n");
        return 1;
    }

    // Send and receive data
    char message[100];
    char server_response[200];

    // Send data to the server
    strcpy(message, "Hello, server!");
    if (send(socket_id, message, strlen(message), 0) == -1) {
        printf("Failed to send data to server\n");
        return 1;
    }

    // Receive data from the server
    if (recv(socket_id, server_response, sizeof(server_response), 0) == -1) {
        printf("Failed to receive data from server\n");
        return 1;
    }

    printf("Server response: %s\n", server_response);

    // Close the socket
    close(socket_id);

    return 0;
}