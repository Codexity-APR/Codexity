#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char**argv)
{
int sockfd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(8080);

    connect(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    char* message = "Hello Server\n";
    char buffer[1024];
    memset(buffer, 0, 1024);
    write(sockfd, message, strlen(message));
    read(sockfd, buffer, 1024);
    printf("%s", buffer);
    close(sockfd);

    return 0;
}
