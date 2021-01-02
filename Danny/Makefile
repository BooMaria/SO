CFLAGS=-lpthread -Wall -Wextra

all: danny 

danny: danny.o fitxer.o conexio.o until.o mensaje.o jpg.o
	gcc -o danny danny.o fitxer.o conexio.o until.o mensaje.o jpg.o -pthread

until.o: until.c until.h
	gcc $(CFLAGS) -c until.c
	
fitxerIn.o: fitxer.c fitxer.h until.h
	gcc $(CFLAGS) -c fitxer.c

conexio.o: conexio.c conexio.h fitxer.h until.h mensaje.h jpg.h
	gcc $(CFLAGS) -c conexio.c

danny.o: danny.c fitxer.h conexio.h until.h jpg.h
	gcc $(CFLAGS) -c danny.c

mensaje.o: mensaje.c mensaje.h
	gcc $(CFLAGS) -c mensaje.c

jpg.o: jpg.c jpg.h
	gcc $(CFLAGS) -c jpg.c

clean:
	rm -f danny *.o