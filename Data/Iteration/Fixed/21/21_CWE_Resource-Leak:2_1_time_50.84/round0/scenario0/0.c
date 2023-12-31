List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `socket()` at line 17, column 19 is not released after line 33, column 9.
 Example: 
  31.     // Connect to server
  32.     if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
  33.         printf("Failed to connect to server\n");
              ^
  34.         return 1;
  35.     }

Error: Resource Leak   resource acquired by call to `socket()` at line 17, column 19 is not released after line 27, column 9.
 Example: 
  25.     server_addr.sin_port = htons(PORT);
  26.     if (inet_pton(AF_INET, IP, &server_addr.sin_addr) <= 0) {
  27.         printf("Invalid address/ Address not supported\n");
              ^
  28.         return 1;
  29.     }


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
    int socket_desc;
    struct sockaddr_in server_addr;
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Failed to create socket\n");
        return 1;
    }
    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, IP, &server_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        return 1;
    }
    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to server\n");
        return 1;
    }
    // TODO: Add your code here
    // Close the socket
    close(socket_desc);
    return 0;
}