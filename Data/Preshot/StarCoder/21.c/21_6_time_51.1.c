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
    struct sockaddr_in servaddr;
    char buffer[1024];
    char *message = "Hello, world!";
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation failed");
        exit(0);
    }
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr(IP);
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1)
    {
        printf("Connection failed");
        exit(0);
    }
    send(sockfd, message, strlen(message), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s\n", buffer);
    close(sockfd);
    return 0;
}

// define a function that takes a message and IP address as input and returns the server response
char* communicate(char* message, char* ip_address) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed\n");
        exit(0);
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr(ip_address);

    if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        printf("Connection failed\n");
        exit(0);
    }

    send(sockfd, message, strlen(message), 0);

    char* buffer = (char*) malloc(sizeof(char) * 1024);
    recv(sockfd, buffer, 1024, 0);
    close(sockfd);

    return buffer;
}