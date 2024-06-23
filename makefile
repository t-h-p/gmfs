CFLAGS= -Wall -O2 $(pkg-config libgvc --cflags)
LDFLAGS= $(pkg-config libgvc --libs)

test: src/main.c src/nodes.c src/graph.c
	gcc $(CFLAGS) $(LDFLAGS) -o bin/test -fsanitize=address src/main.c src/nodes.c src/graph.c
