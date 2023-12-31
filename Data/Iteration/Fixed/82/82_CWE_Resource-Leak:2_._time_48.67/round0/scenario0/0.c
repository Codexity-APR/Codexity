List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `socket()` at line 16, column 14 is not released after line 30, column 9.
 Example: 
  28.     
  29.     if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
  30.         printf("Error in connection.\n");
              ^
  31.         return 1;
  32.     }

Error: Resource Leak   resource acquired by call to `socket()` at line 16, column 14 is not released after line 25, column 9.
 Example: 
  23.     servaddr.sin_port = htons(8080);
  24.     if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
  25.         printf("Invalid IP address.\n");
              ^
  26.         return 1;
  27.     }


#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
int main(int argc, char**argv)
{
    int sockfd, n;
    char buffer[1024];
    struct sockaddr_in servaddr;
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error in creating socket.\n");
        return 1;
    }
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("Invalid IP address.\n");
        return 1;
    }
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error in connection.\n");
        return 1;
    }
    printf("Connected to server.\n");
    // TODO: Add your code here
    close(sockfd);
    return 0;
}