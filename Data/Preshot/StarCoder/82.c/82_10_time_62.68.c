#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char**argv)
{
    int sockfd;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE], recvline[MAXLINE];

    if(argc != 3)
    {
        printf("Usage: ./client <IP address> <port number>\n");
        return 1;
    }

    // Create a socket for the client
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("socket creation failed");
        return 1;
    }

    // Set address information for the server to connect to
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connection failed");
        return 1;
    }

    printf("Connected to the server.\n");

    while(1)
    {
        // Get input from the user
        printf("Enter message to send (type 'exit' to close connection): ");
        fgets(sendline, MAXLINE, stdin);

        // Send the data to the server
        send(sockfd, sendline, strlen(sendline), 0);

        // Check if the user wants to exit
        if(strncmp(sendline, "exit", 4) == 0)
        {
            printf("Closing connection.\n");
            break;
        }

        // Receive data from the server
        int n = recv(sockfd, recvline, MAXLINE, 0);
        if(n < 0)
        {
            perror("recv failed");
            break;
        }
        recvline[n] = '\0';
        printf("Received message from server: %s\n", recvline);
    }

    // Close the connection and the socket
    close(sockfd);
    printf("Connection closed.\n");

    return 0;
}