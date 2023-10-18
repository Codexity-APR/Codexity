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
    int socket_desc;
    struct sockaddr_in server;
    char message[100], server_reply[2000];
    
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }
    
    server.sin_addr.s_addr = inet_addr(IP);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    
    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection error");
        return 1;
    }
    
    printf("Connected to server\n");
    
    // Send some data
    strcpy(message, "GET / HTTP/1.1\r\n\r\n");
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }
    printf("Data sent\n");
    
    // Receive a reply from the server
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        printf("Receive failed");
        return 1;
    }
    printf("Reply received:\n%s\n", server_reply);
    
    close(socket_desc);
    
    return 0;
}