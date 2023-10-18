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
    int sock;
    struct sockaddr_in server_addr;
    char message[100];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }

    server_addr.sin_addr.s_addr = inet_addr(IP);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Connection failed\n");
        return 1;
    }

    printf("Connected to server\n");

    // Send data to server
    strcpy(message, "Hello server!");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        printf("Failed to send data\n");
        return 1;
    }

    printf("Data sent to server: %s\n", message);

    // Receive data from server
    if (recv(sock, message, sizeof(message), 0) < 0)
    {
        printf("Failed to receive data\n");
        return 1;
    }

    printf("Data received from server: %s\n", message);

    // Close the socket
    close(sock);

    return 0;
}