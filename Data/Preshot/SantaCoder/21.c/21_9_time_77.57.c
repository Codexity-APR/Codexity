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
    int sockfd;
    struct sockaddr_in server_address;
    char *message = "Hello, server!";

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, IP, &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("Failed to send message");
        exit(EXIT_FAILURE);
    }

    printf("Message sent to server.\n");

    close(sockfd);

    return 0;
}