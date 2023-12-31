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
    char server_response[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
        return 1;
    }

    server_addr.sin_addr.s_addr = inet_addr(IP);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Connection error");
        close(socket_desc); // Close the socket before returning
        return 1;
    }

    printf("Connected to server\n");

    // Receive and print server response
    if (recv(socket_desc, server_response, sizeof(server_response), 0) < 0)
    {
        printf("Receive failed");
        close(socket_desc); // Close the socket before returning
        return 1;
    }

    printf("Server response: %s\n", server_response);

    close(socket_desc); // Close the socket before returning
    return 0;
}