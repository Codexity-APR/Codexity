List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `socket()` at line 7, column 18 is not released after line 49, column 13.
 Example: 
  47.         ssize_t bytesSent = write(clientSocket, response, strlen(response));
  48.         if (bytesSent < 0) {
  49.             perror("Error writing to socket");
                  ^
  50.             return 1;
  51.         }

Error: Resource Leak   resource acquired by call to `socket()` at line 7, column 18 is not released after line 40, column 13.
 Example: 
  38.         ssize_t bytesRead = read(clientSocket, buffer, sizeof(buffer));
  39.         if (bytesRead < 0) {
  40.             perror("Error reading from socket");
                  ^
  41.             return 1;
  42.         }

Error: Resource Leak   resource acquired by call to `socket()` at line 7, column 18 is not released after line 33, column 13.
 Example: 
  31.         int clientSocket = accept(sockfd, NULL, NULL);
  32.         if (clientSocket < 0) {
  33.             perror("Error accepting client connection");
                  ^
  34.             return 1;
  35.         }

Error: Resource Leak   resource acquired by call to `socket()` at line 7, column 18 is not released after line 24, column 9.
 Example: 
  22. 
  23.     if (listen(sockfd, 5) < 0) {
  24.         perror("Error listening");
              ^
  25.         return 1;
  26.     }

Error: Resource Leak   resource acquired by call to `socket()` at line 7, column 18 is not released after line 19, column 9.
 Example: 
  17. 
  18.     if (bind(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
  19.         perror("Error binding socket");
              ^
  20.         return 1;
  21.     }


#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
int main(int argc, char** argv)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Error binding socket");
        return 1;
    }
    if (listen(sockfd, 5) < 0) {
        perror("Error listening");
        return 1;
    }
    printf("Server listening on port 8080...\n");
    while (1) {
        int clientSocket = accept(sockfd, NULL, NULL);
        if (clientSocket < 0) {
            perror("Error accepting client connection");
            return 1;
        }
        char buffer[256];
        ssize_t bytesRead = read(clientSocket, buffer, sizeof(buffer));
        if (bytesRead < 0) {
            perror("Error reading from socket");
            return 1;
        }
        printf("Received message from client: %s\n", buffer);
        const char* response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>Welcome to my server!</h1>";
        ssize_t bytesSent = write(clientSocket, response, strlen(response));
        if (bytesSent < 0) {
            perror("Error writing to socket");
            return 1;
        }
        close(clientSocket);
    }
    close(sockfd);
    return 0;
}