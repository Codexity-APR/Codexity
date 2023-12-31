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

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP);

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed\n");
        return 1;
    }

    printf("Connected to server\n");

    // TODO: Add your code here

    // Close the socket
    close(socket_desc);

    return 0;
}