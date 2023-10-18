#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
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
        puts("Bind failed");
        return 1;
    }
    puts("Bind done");

    // Listen
    listen(socket_desc, 3);

    // Accept incoming connection
    c = sizeof(struct sockaddr_in);
    puts("Waiting for incoming connections...");
    new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (new_socket < 0) {
        perror("Accept failed");
        return 1;
    }
    puts("Connection accepted");

    // Reply to the client
    message = "Hello client, I have received your connection. And now I will assign a handler for you.\n";
    write(new_socket, message, strlen(message));

    return 0;
}