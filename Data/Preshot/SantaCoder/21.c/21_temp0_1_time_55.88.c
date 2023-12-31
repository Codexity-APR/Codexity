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
    if (sock == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, IP, &server_address.sin_addr) <= 0) {
        perror("invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // code to send and receive data goes here

    close(sock);
    return 0;
}