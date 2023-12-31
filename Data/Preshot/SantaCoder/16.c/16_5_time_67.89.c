#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		return 1;
	}

	char *host = argv[1];
	int port = PORT;

	if (argc > 2)
	{
		port = argv[2];
	}

	in_addr addr;
	addr.sin_addr = in_addr_dup(host);
	addr.sin_port = port;

	in_addr *addr_ptr = in_addr_malloc(sizeof(in_addr));
	if (addr_ptr == NULL)
	{
		printf("Failed to allocate in_addr\n");
		return 1;
	}

	in_addr_free(addr_ptr);

	printf("in_addr: %s\n", addr.sin_addr);
	printf("in_addr: %s\n", addr.sin_port);

	return 0;
}