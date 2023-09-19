CC = clang
CFLAGS = -Wall -Werror -g

all: swap ints array node listSum listDelete

swap: swap.c
	$(CC) $(CFLAGS) -o swap swap.c

ints: ints.c
	$(CC) $(CFLAGS) -o ints ints.c

array: array.c
	$(CC) $(CFLAGS) -o array array.c

node: node.c
	$(CC) $(CFLAGS) -o node node.c

listSum: listSum.c
	$(CC) $(CFLAGS) -o listSum listSum.c

listDelete: listDelete.c
	$(CC) $(CFLAGS) -o listDelete listDelete.c

##############################################################################

clean:
	rm -f swap ints array node listSum listDelete
