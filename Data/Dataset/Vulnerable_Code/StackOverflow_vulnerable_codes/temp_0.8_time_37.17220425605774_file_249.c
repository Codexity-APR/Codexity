#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    int bindStatus = bind(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    if (bindStatus < 0) {
        perror("Error binding socket");
        return 1;
    }

    int listenStatus = listen(sockfd, 5);
    if (listenStatus < 0) {
        perror("Error listening on socket");
        return 1;
    }

    printf("Server listening on port 8080...\n");

    while (1) {
        struct sockaddr_in clientAddress;
        socklen_t clientLength = sizeof(clientAddress);
        int clientSocket = accept(sockfd, (struct sockaddr*)&clientAddress, &clientLength);
        if (clientSocket < 0) {
            perror("Error accepting client connection");
            return 1;
        }

        printf("Client connected\n");

        // Handle client request and send response

        close(clientSocket);
        printf("Client disconnected\n");
    }

    close(sockfd);

    return 0;
}