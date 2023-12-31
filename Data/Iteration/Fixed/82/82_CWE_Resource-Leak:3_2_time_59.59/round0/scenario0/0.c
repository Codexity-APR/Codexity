List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `socket()` at line 10, column 14 is not released after line 38, column 9.
 Example: 
  36.     int clientSockfd = accept(sockfd, (struct sockaddr*) &clientAddr, &clientAddrLen);
  37.     if (clientSockfd < 0) {
  38.         perror("Error accepting connection");
              ^
  39.         return 1;
  40.     }

Error: Resource Leak   resource acquired by call to `socket()` at line 10, column 14 is not released after line 29, column 9.
 Example: 
  27.     // Listen for incoming connections
  28.     if (listen(sockfd, 10) < 0) {
  29.         perror("Error listening");
              ^
  30.         return 1;
  31.     }

Error: Resource Leak   resource acquired by call to `socket()` at line 10, column 14 is not released after line 23, column 9.
 Example: 
  21.     // Bind socket to the specified address and port
  22.     if (bind(sockfd, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0) {
  23.         perror("Error binding socket");
              ^
  24.         return 1;
  25.     }


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