#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }
    
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }
    
    // Set up address structure
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    
    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connect failed. Error");
        return 1;
    }
    
    printf("Connected successfully!\n");
    
    close(sock);
    return 0;
}