#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char**argv)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sockfd, 10) < 0) {
        perror("listen");
        return 1;
    }

    printf("Server started. Listening on port 8080...\n");

    // TODO: Accept and handle incoming connections

    return 0;
}