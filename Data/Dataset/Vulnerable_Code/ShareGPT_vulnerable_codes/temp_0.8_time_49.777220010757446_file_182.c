#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int socket_desc, client_sock, c;
    struct sockaddr_in server, client;
    char message[2000], client_reply[2000];
    
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
        return 1;
    }
    
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
    
    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("bind failed. Error");
        return 1;
    }
    printf("Bind done\n");
    
    // Listen
    listen(socket_desc, 3);
    
    // Accept incoming connections
    printf("Waiting for incoming connections...\n");
    c = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
    printf("Connection accepted\n");
    
    // Receive message from client
    if (recv(client_sock, client_reply, 2000, 0) < 0)
    {
        printf("recv failed");
        return 1;
    }
    printf("Message from client: %s\n", client_reply);
    
    // Send message to client
    strcpy(message, "Hello from server!");
    if (send(client_sock, message, strlen(message), 0) < 0)
    {
        printf("send failed");
        return 1;
    }
    printf("Message sent to client\n");
    
    // Close the socket
    close(socket_desc);
    
    return 0;
}