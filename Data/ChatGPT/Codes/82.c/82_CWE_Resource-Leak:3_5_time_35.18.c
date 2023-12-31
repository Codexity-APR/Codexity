#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int sockfd;
    struct sockaddr_in serverAddr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    // Initialize server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to the specified address and port
    if (bind(sockfd, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 10) < 0) {
        perror("Error listening");
        return 1;
    }

    // Accept incoming connection
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int clientSockfd = accept(sockfd, (struct sockaddr*) &clientAddr, &clientAddrLen);
    if (clientSockfd < 0) {
        perror("Error accepting connection");
        return 1;
    }

    // Handle client request
    // TODO: Add code to handle client request

    // Close sockets
    close(clientSockfd);
    close(sockfd);
  
    return 0;
}