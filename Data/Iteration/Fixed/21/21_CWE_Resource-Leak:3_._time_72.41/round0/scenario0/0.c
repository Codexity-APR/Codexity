List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `socket()` at line 18, column 12 is not released after line 51, column 9.
 Example: 
  49.     if (recv(sock, message, sizeof(message), 0) < 0)
  50.     {
  51.         printf("Receive failed");
              ^
  52.         return 1;
  53.     }

Error: Resource Leak   resource acquired by call to `socket()` at line 18, column 12 is not released after line 42, column 9.
 Example: 
  40.     if (send(sock, message, strlen(message), 0) < 0)
  41.     {
  42.         printf("Send failed");
              ^
  43.         return 1;
  44.     }

Error: Resource Leak   resource acquired by call to `socket()` at line 18, column 12 is not released after line 32, column 9.
 Example: 
  30.     if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
  31.     {
  32.         perror("Connect failed. Error");
              ^
  33.         return 1;
  34.     }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORT 1025
#define IP "172.22.100.100"
int main()
{
    int sock;
    struct sockaddr_in server;
    char message[1000];
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Failed to create socket");
        return 1;
    }
    server.sin_addr.s_addr = inet_addr(IP);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Connect failed. Error");
        return 1;
    }
    printf("Connected to server\n");
    // Send some data
    strcpy(message, "Hello server!");
    if (send(sock, message, strlen(message), 0) < 0)
    {
        printf("Send failed");
        return 1;
    }
    printf("Data sent\n");
    // Receive a reply from the server
    if (recv(sock, message, sizeof(message), 0) < 0)
    {
        printf("Receive failed");
        return 1;
    }
    printf("Server reply: %s\n", message);
    // Close the socket
    close(sock);
    return 0;
}