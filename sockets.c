#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#define IP "74.6.231.20" // got it using !host www.google.se
#define PORT 80 //http

int main() {
	int s;
	struct sockaddr_in sock;
	char buf[512];
	char *data;

	data = "HEAD / HTTP/1.0\r\n\n";
	
	s = socket(AF_INET, SOCK_STREAM, 0);
	if ( s < 0) {
		printf("socket() error \n");
		return -1;
	}

	sock.sin_addr.s_addr = inet_addr(IP);
	sock.sin_port = htons(PORT);
	sock.sin_family = AF_INET;

	if (connect(s, (struct sockaddr *)&sock, sizeof(struct sockaddr_in))) {
		printf("Connect() error \n");
		close(s);
		return -1;
	}
	
	write(s, data, strlen(data));
	memset(buf, 0, 512);
	read(s, buf, 511);
	close(s);
	printf("\n%s\n", buf);

	return 0;
}
