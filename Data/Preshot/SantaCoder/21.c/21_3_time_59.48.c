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
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, IP, &(server_addr.sin_addr));

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    char msg[] = "Hello, server!";
    if (send(sock, msg, strlen(msg), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    close(sock);

    return 0;
}