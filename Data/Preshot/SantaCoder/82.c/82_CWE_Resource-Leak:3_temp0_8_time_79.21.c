#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char**argv)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8080);
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    int bind_result = bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    if (bind_result < 0) {
        perror("Error binding socket");
        return 1;
    }

    int listen_result = listen(sockfd, 10);
    if (listen_result < 0) {
        perror("Error listening on socket");
        return 1;
    }

    printf("Server listening on port 8080...\n");

    while (1) {
        struct sockaddr_in clientaddr;
        socklen_t clientaddrlen = sizeof(clientaddr);
        int clientsockfd = accept(sockfd, (struct sockaddr*)&clientaddr, &clientaddrlen);
        if (clientsockfd < 0) {
            perror("Error accepting client connection");
            return 1;
        }

        printf("Client connected from %s:%d\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

        // Do something with the client connection...

        close(clientsockfd);
    }

    close(sockfd);
    return 0;
}