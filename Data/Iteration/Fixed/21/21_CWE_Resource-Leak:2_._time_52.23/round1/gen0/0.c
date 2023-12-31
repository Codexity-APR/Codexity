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
    char server_response[1024];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP);

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection error\n");
        close(socket_desc); // Release the socket resource
        return 1;
    }

    // Receive and print server response
    if (recv(socket_desc, server_response, sizeof(server_response), 0) < 0) {
        printf("Receive failed\n");
        close(socket_desc); // Release the socket resource
        return 1;
    }

    printf("Server response: %s\n", server_response);

    close(socket_desc); // Release the socket resource

    return 0;
}