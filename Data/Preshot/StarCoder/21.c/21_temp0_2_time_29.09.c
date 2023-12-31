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
	int sockfd;
	struct sockaddr_in servaddr;
	char buffer[1024];
	char *message = "Hello, world!";
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		printf("Socket creation failed");
		exit(0);
	}
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = inet_addr(IP);
	if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1)
	{
		printf("Connection failed");
		exit(0);
	}
	send(sockfd, message, strlen(message), 0);
	recv(sockfd, buffer, 1024, 0);
	printf("%s\n", buffer);
	close(sockfd);
	return 0;
}