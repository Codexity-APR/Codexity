#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s <ip>\n", argv[0]);
		return 1;
	}
	
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		perror("socket");
		return 1;
	}
	
	struct sockaddr_in server;
	server.sin_addr.s_addr = inet_addr(argv[1]);
	server.sin_family = AF_INET;
	server.sin_port = htons(80); // default HTTP port
	
	if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
		perror("connect");
		return 1;
	}
	
	// send request
	
	const char *message = "GET / HTTP/1.1\r\n\r\n";
	if (send(sock, message, strlen(message), 0) < 0) {
		perror("send");
		return 1;
	}
	
	// receive response
	
	char buffer[2048];
	int len = recv(sock, buffer, sizeof(buffer), 0);
	if (len < 0) {
		perror("recv");
		return 1;
	}
	
	buffer[len] = '\0';
	printf("%s", buffer);
	
	close(sock);
	
	return 0;
}