#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char**argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 2) {
        fprintf(stderr, "usage: a.out <IPaddress>\n");
        return 1;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        return 1;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);  /* daytime server */
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error for %s\n", argv[1]);
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        return 1;
    }

    while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;        /* null terminate */
        if (fputs(recvline, stdout) == EOF) {
            perror("fputs error");
            return 1;
        }
    }
    if (n < 0) {
        perror("read error");
        return 1;
    }
    return 0;
}