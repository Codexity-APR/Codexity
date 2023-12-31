#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;
	char *hello = "Hello from client";
	char buffer[1024];
	int n;
	if(argc!= 3)
	{
		printf("Invalid number of arguments\n");
		printf("Correct usage: %s <IP> <port>\n", argv[0]);
		return -1;
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1)
	{
		printf("socket creation failed\n");
		return -1;
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);
	if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1)
	{
		printf("connection with the server failed\n");
		return -1;
	}
	n = write(sockfd, hello, strlen(hello));
	if(n < 0)
	{
		printf("write failed\n");
		return -1;
	}
	bzero(buffer, 1024);
	n = read(sockfd, buffer, 1024);
	if(n < 0)
	{
		printf("read failed\n");
		return -1;
	}
	printf("Server response: %s\n", buffer);
	close(sockfd);
	return 0;
} 

// The code above establishes a connection with a server and sends a "Hello from client" message. Now we will add error handling to the code to make it more robust. 
// We will also handle the case when the server sends a response bigger than the allocated buffer size.

#define BUFFER_SIZE 2048

int main(int argc, char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;
	char *hello = "Hello from client";
	char buffer[BUFFER_SIZE];
	int n;

	if(argc!= 3)
	{
		fprintf(stderr, "Invalid number of arguments\n");
		fprintf(stderr, "Correct usage: %s <IP> <port>\n", argv[0]);
		return -1;
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1)
	{
		perror("socket creation failed");
		return -1;
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);

	if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1)
	{
		perror("connection with the server failed");
		close(sockfd);
		return -1;
	}

	n = write(sockfd, hello, strlen(hello));
	if(n < 0)
	{
		perror("write failed");
		close(sockfd);
		return -1;
	}

	bzero(buffer, BUFFER_SIZE);
	n = read(sockfd, buffer, BUFFER_SIZE - 1); // Leave the last byte for null-terminator.
	if(n < 0)
	{
		perror("read failed");
		close(sockfd);
		return -1;
	}

	buffer[n] = '\0'; // Null-terminate the buffer.

	printf("Server response: %s\n", buffer);

	close(sockfd);

	return 0;
}