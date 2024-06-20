CFLAGS= -Wall -O2 $(pkg-config libgvc --cflags)
LDFLAGS= $(pkg-config libgvc --libs)

test: src/main.c
	gcc $(CFLAGS) $(LDFLAGS) -o bin/test src/main.c
