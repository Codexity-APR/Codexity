#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    int serverSocket;
    struct sockaddr_in serverAddress;

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        perror("Failed to create socket");
        return -1;
    }

    // Set up server address
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080); // Change the port number if needed
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) < 0)
    {
        perror("Failed to bind socket");
        return -1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) < 0)
    {
        perror("Failed to listen");
        return -1;
    }

    printf("Server listening on port 8080\n");

    // Accept incoming connections
    int clientSocket;
    struct sockaddr_in clientAddress;
    int clientAddressLength = sizeof(clientAddress);

    clientSocket = accept(serverSocket, (struct sockaddr*) &clientAddress, &clientAddressLength);
    if (clientSocket < 0)
    {
        perror("Failed to accept connection");
        return -1;
    }

    printf("Client connected\n");

    // Do something with the client connection

    // Close the sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}