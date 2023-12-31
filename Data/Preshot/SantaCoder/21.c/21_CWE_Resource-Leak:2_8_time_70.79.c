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
    if(sock == -1){
        printf("Error: Could not create socket");
        return -1;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(IP);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0){
        printf("Error: Could not connect");
        return -1;
    }

    printf("Connected to server %s:%d\n", IP, PORT);

    // send data to server
    char message[] = "Hello server!";
    if(send(sock, message, strlen(message), 0) < 0){
        printf("Error: Send failed");
        return -1;
    }

    printf("Data Sent\n");

    // close the socket
    close(sock);
    printf("Socket closed\n");

    return 0;
}