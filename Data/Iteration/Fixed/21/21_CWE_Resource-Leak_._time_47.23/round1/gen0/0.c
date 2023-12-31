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
    int socket_desc;
    struct sockaddr_in server_addr;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(IP);
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Failed to connect to server\n");
        close(socket_desc); // Close the socket before returning
        return 1;
    }

    // Send and receive data

    // Close the socket
    close(socket_desc);

    return 0;
}