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
        printf("Failed to create socket\n");
        return 1;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, IP, &server_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        return 1;
    }

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to server\n");
        return 1;
    }

    // TODO: Add your code here

    // Close the socket
    close(socket_desc);

    return 0;
}