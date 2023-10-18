#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    if (listen(sockfd, 10) < 0) {
        perror("Error listening");
        return 1;
    }

    printf("Server listening on port 8080\n");

    while (1) {
        struct sockaddr_in clientAddress;
        int clientSockfd = accept(sockfd, (struct sockaddr*)&clientAddress, sizeof(clientAddress));
        if (clientSockfd < 0) {
            perror("Error accepting connection");
            return 1;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));

        // Add your code to handle the connection here

        close(clientSockfd);
    }

    close(sockfd);
    return 0;
}