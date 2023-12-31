#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Could not connect");
        return 1;
    }

    printf("Connected");
    close(sock);
    return 0;
}