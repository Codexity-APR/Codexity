List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `socket()` at line 13, column 14 is not released after line 53, column 9.
 Example: 
  51.     n = write(newsockfd, "Server acknowledges the message", 30);
  52.     if (n < 0) {
  53.         perror("Error writing to socket");
              ^
  54.         return 1;
  55.     }

Error: Resource Leak   resource acquired by call to `socket()` at line 13, column 14 is not released after line 46, column 9.
 Example: 
  44.     n = read(newsockfd, buffer, 255);
  45.     if (n < 0) {
  46.         perror("Error reading from socket");
              ^
  47.         return 1;
  48.     }

Error: Resource Leak   resource acquired by call to `socket()` at line 13, column 14 is not released after line 38, column 9.
 Example: 
  36.     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
  37.     if (newsockfd < 0) {
  38.         perror("Error on accept");
              ^
  39.         return 1;
  40.     }

Error: Resource Leak   resource acquired by call to `socket()` at line 13, column 14 is not released after line 27, column 9.
 Example: 
  25.     // Bind the socket to the server address
  26.     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
  27.         perror("Error on binding");
              ^
  28.         return 1;
  29.     }


#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
int main(int argc, char**argv)
{
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
        return 1;
    }
    // Listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    // Accept a client connection
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("Error on accept");
        return 1;
    }
    // Read from and write to the client
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
        perror("Error reading from socket");
        return 1;
    }
    printf("Received message: %s\n", buffer);
    n = write(newsockfd, "Server acknowledges the message", 30);
    if (n < 0) {
        perror("Error writing to socket");
        return 1;
    }
    // Close the sockets
    close(newsockfd);
    close(sockfd);
    return 0;
}