#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char**argv)
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    char *hello = "Hello from client";
    char buffer[1024];
    int n, len;
    
    if(argc != 2)
    {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0)
    {
        perror("Socket creation failed");
        return 1;
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    
    sendto(sockfd, (const char*)hello, strlen(hello), 0, (const struct sockaddr*)&servaddr, sizeof(servaddr));
    printf("Hello message sent.\n");
    
    len = sizeof(cliaddr);
    n = recvfrom(sockfd, (char *)buffer, 1024, 0, (struct sockaddr*)&cliaddr, &len);
    buffer[n] = '\0';
    printf("Server : %s\n", buffer);
    
    close(sockfd);
    return 0;
}