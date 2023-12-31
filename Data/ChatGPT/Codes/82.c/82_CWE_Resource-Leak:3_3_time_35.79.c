#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Specify the server address details
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified address and port
    if (bind(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 10) < 0) {
        perror("Error listening for connections");
        return 1;
    }

    // Accept incoming connections
    int clientSocket = accept(sockfd, NULL, NULL);

    if (clientSocket < 0) {
        perror("Error accepting connection");
        return 1;
    }

    // Send data to the client
    char* message = "Hello, client!";
    send(clientSocket, message, strlen(message), 0);

    // Close the sockets
    close(clientSocket);
    close(sockfd);

    return 0;
}