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