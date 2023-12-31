#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    listen(sockfd, 5);

    printf("Server listening on port 8080\n");

    return 0;
}