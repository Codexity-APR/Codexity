#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <ip>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Could not create socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Could not connect");
        return 1;
    }

    printf("Connected to %s\n", argv[1]);

    close(sock);

    return 0;
}