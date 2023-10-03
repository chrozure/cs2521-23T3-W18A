CC = clang
CFLAGS = -Wall -Wvla -Werror -g

all: testSet bstFunctions

########################################################################

testSet: testSet.o Set.o
	$(CC) $(CFLAGS) -o testSet testSet.o Set.o

testSet.o: testSet.c Set.h

Set.o: Set.c Set.h

########################################################################

bstFunctions: bstFunctions.o bst.o
	$(CC) $(CFLAGS) -o bstFunctions bstFunctions.o bst.o

bstFunctions.o: bstFunctions.c bst.h

bst.o: bst.c bst.h

########################################################################

clean:
	rm -f *.o testSet bstFunctions