#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char** argv) {
    int sockfd, n;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE];
    char *message = "Hello from client";

    if (argc != 3) {
        printf("Usage: %s <server IP address> <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_address, '0', sizeof(server_address));

    // Set server address and port
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        return 1;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send message to server
    if (write(sockfd, message, strlen(message)) < 0) {
        printf("Error sending message to server\n");
        return 1;
    }

    // Read response from server
    if ((n = read(sockfd, buffer, MAX_BUFFER_SIZE)) < 0) {
        printf("Error receiving response from server\n");
        return 1;
    }

    printf("Response from server: %s\n", buffer);

    close(sockfd);

    return 0;
}