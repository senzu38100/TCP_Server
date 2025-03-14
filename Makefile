CC = gcc
CFLAGS = -Wall -Wextra -g

all:
	gcc sockets.c -o sockets

clean:
	rm -f sockets
