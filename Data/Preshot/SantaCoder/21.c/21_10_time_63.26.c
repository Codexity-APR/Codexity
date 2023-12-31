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
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(IP);

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char message[] = "Hello, server!\n";
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    printf("Message sent to server: %s", message);

    close(sock);

    return 0;
}