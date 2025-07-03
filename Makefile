CC=gcc
CFLAGS=-I. -lm

qrc: qrc.o
	$(CC) $(CFLAGS) -o qrc qrc.o

clean:
	rm -f *.o qrc
