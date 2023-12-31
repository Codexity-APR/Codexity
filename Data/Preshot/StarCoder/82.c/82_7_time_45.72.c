#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char**argv)
{
    int sockfd;
    struct sockaddr_in servaddr;
    char *hello = "Hello from client";
    char buffer[1024];
    int n;

    if (argc != 3)
    {
        printf("Invalid number of arguments\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation failed\n");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1)
    {
        printf("Connection failed\n");
        return 1;
    }

    n = write(sockfd, hello, strlen(hello));
    if (n == -1)
    {
        printf("Write failed\n");
        return 1;
    }

    n = read(sockfd, buffer, 1024);
    if (n == -1)
    {
        printf("Read failed\n");
        return 1;
    }

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}