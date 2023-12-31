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
    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, IP, &server.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        exit(EXIT_FAILURE);
    }
    
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    
    // Code to send and receive data
    
    close(sock);
    
    return 0;
}