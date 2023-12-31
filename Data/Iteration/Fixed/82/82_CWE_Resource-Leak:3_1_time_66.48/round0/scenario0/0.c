List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `socket()` at line 6, column 18 is not released after line 41, column 13.
 Example: 
  39.         
  40.         if (clientSockfd < 0) {
  41.             perror("Error accepting connection");
                  ^
  42.             return 1;
  43.         }

Error: Resource Leak   resource acquired by call to `socket()` at line 6, column 18 is not released after line 28, column 9.
 Example: 
  26.     
  27.     if (listenResult < 0) {
  28.         perror("Error listening on socket");
              ^
  29.         return 1;
  30.     }

Error: Resource Leak   resource acquired by call to `socket()` at line 6, column 18 is not released after line 21, column 9.
 Example: 
  19.     
  20.     if (bindResult < 0) {
  21.         perror("Error binding socket");
              ^
  22.         return 1;
  23.     }


#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
int main(int argc, char** argv) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    int bindResult = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (bindResult < 0) {
        perror("Error binding socket");
        return 1;
    }
    int listenResult = listen(sockfd, 10);
    if (listenResult < 0) {
        perror("Error listening on socket");
        return 1;
    }
    printf("Server listening on port 8080...\n");
    while (1) {
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);
        int clientSockfd = accept(sockfd, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSockfd < 0) {
            perror("Error accepting connection");
            return 1;
        }
        printf("Client connected\n");
        // TODO: Handle client connection
        close(clientSockfd);
        printf("Client disconnected\n");
    }
    close(sockfd);
    return 0;
}