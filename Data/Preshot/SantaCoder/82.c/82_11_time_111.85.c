#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    // clear address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // set port number
    portno = 1234;

    // set IP address to localhost
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // bind socket to specified port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        return 1;
    }

    // listen for connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // accept incoming connection
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        return 1;
    }

    // receive message from client
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        return 1;
    }
    printf("Here is the message: %s\n", buffer);

    // send message to client
    n = write(newsockfd, "I got your message", 18);
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }

    // close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}