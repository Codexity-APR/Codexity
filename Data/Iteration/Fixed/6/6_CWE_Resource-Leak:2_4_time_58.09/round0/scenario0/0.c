List of vulnerabilities detected: 
Error: Resource Leak   resource acquired by call to `socket()` at line 13, column 19 is not released after line 37, column 5.
 Example: 
  35.     printf("Waiting for incoming connections...\n");
  36.     c = sizeof(struct sockaddr_in);
  37.     new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
          ^
  38.     if (new_socket < 0) {
  39.         perror("accept failed");

Error: Resource Leak   resource acquired by call to `socket()` at line 13, column 19 is not released after line 26, column 9.
 Example: 
  24.     // Bind
  25.     if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
  26.         perror("bind failed. Error");
              ^
  27.         return 1;
  28.     }


#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
    int socket_desc, new_socket, c;
    struct sockaddr_in server, client;
    char *message;
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }
    printf("Bind done\n");
    // Listen
    listen(socket_desc, 3);
    // Accept incoming connection
    printf("Waiting for incoming connections...\n");
    c = sizeof(struct sockaddr_in);
    new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if (new_socket < 0) {
        perror("accept failed");
        return 1;
    }
    printf("Connection accepted\n");
    // Reply to the client
    message = "Hello from server!\n";
    write(new_socket, message, strlen(message));
    return 0;
}