#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
    listen(serverSocket, 5);

    int clientSocket;
    clientSocket = accept(serverSocket, NULL, NULL);

    char response[1024] = "Hello, World!";
    send(clientSocket, response, sizeof(response), 0);

    return 0;
}