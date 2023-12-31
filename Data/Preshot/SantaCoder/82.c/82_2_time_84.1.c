#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        return 1;
    }
    
    struct sockaddr_in serv_addr;
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }
    
    listen(sockfd,5);
    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);
    
    int newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        printf("Error accepting connection\n");
        return 1;
    }
    
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    int n = read(newsockfd, buffer, sizeof(buffer)-1);
    if (n < 0) {
        printf("Error reading from socket\n");
        return 1;
    }
    
    printf("Here is the message: %s\n",buffer);
    n = write(newsockfd,"I got your message",18);
    if (n < 0) {
        printf("Error writing to socket\n");
        return 1;
    }
    
    return 0;
}