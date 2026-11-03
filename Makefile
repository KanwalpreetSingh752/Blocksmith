CC = gcc
CFLAGS = -Wall -Wextra -g

allocator: src/main.c
	$(CC) $(CFLAGS) src/main.c -o allocator

run: allocator
	./allocator

clean:
	rm -f allocator