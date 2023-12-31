#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    // Set server address properties
    portno = 1234;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        close(sockfd); // Close the socket before returning
        return 1;
    }

    // Listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Accept a client connection
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("Error on accept");
        close(sockfd); // Close the socket before returning
        return 1;
    }

    // Read from and write to the client
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
        perror("Error reading from socket");
        close(newsockfd); // Close the socket before returning
        close(sockfd); // Close the socket before returning
        return 1;
    }
    printf("Received message: %s\n", buffer);

    n = write(newsockfd, "Server acknowledges the message", 30);
    if (n < 0) {
        perror("Error writing to socket");
        close(newsockfd); // Close the socket before returning
        close(sockfd); // Close the socket before returning
        return 1;
    }

    // Close the sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}