List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `socket()` at line 14, column 19 is not released after line 37, column 9.
 Example: 
  35.     if (send(socket_desc, message, strlen(message), 0) < 0)
  36.     {
  37.         puts("Send failed");
              ^
  38.         return 1;
  39.     }

Error: Resource Leak   resource acquired by call to `socket()` at line 14, column 19 is not released after line 27, column 9.
 Example: 
  25.     if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
  26.     {
  27.         puts("Connect error");
              ^
  28.         return 1;
  29.     }


#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[2000];
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        puts("Connect error");
        return 1;
    }
    puts("Connected");
    // Send some data
    message = "GET / HTTP/1.1\r\n\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    puts("Data Sent\n");
    // Receive a reply from the server
    if (recv(socket_desc, server_reply, 2000, 0) < 0)
    {
        puts("recv failed");
    }
    puts("Reply received\n");
    puts(server_reply);
    // Close the socket
    close(socket_desc);
    return 0;
}