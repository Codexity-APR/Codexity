#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Check if port number is provided
    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        return 1;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    // Check if socket creation failed
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        return 1;
    }

    // Clear server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = atoi(argv[1]);

    // Set server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR on binding\n");
        return 1;
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    // Accept incoming connection
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    // Check if accept failed
    if (newsockfd < 0) {
        fprintf(stderr, "ERROR on accept\n");
        return 1;
    }

    // Clear buffer
    bzero(buffer, 256);

    // Read from socket
    n = read(newsockfd, buffer, 255);

    // Check if read failed
    if (n < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        return 1;
    }

    // Print message received
    printf("Message received: %s\n", buffer);

    // Write response to socket
    n = write(newsockfd, "I got your message", 18);

    // Check if write failed
    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        return 1;
    }

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}