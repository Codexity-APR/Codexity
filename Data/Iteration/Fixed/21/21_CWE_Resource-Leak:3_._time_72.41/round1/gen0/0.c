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
    struct sockaddr_in server;
    char message[1000];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Failed to create socket");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr(IP);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Connect failed. Error");
        close(sock); // Close the socket before returning
        return 1;
    }

    printf("Connected to server\n");

    // Send some data
    strcpy(message, "Hello server!");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed");
        close(sock); // Close the socket before returning
        return 1;
    }

    printf("Data sent\n");

    // Receive a reply from the server
    if (recv(sock, message, sizeof(message), 0) < 0)
    {
        printf("Receive failed");
        close(sock); // Close the socket before returning
        return 1;
    }

    printf("Server reply: %s\n", message);

    // Close the socket
    close(sock);

    return 0;
}