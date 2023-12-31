#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error in socket");
        return -1;
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error in connect");
        return -1;
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter a message: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("Error in send");
            return -1;
        }

        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        memset(buffer, 0, sizeof(buffer));

        if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("Error in receive");
            return -1;
        }

        printf("Server response: %s", buffer);
    }

    close(sockfd);

    return 0;
}