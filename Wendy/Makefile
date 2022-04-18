CFLAGS=-Wall -Wextra -lpthread

all: servidor

servidor: servidor.o servidorDedicat.o until.o mensaje.o jpg.o fitxer.o
	gcc -o wendy servidor.o servidorDedicat.o until.o mensaje.o jpg.o fitxer.o -pthread

servidor.o: servidor.c servidorDedicat.h servidorDedicat.h until.h mensaje.h jpg.h semaphore_v2.h fitxer.h
	gcc $(CFLAGS) -c servidor.c

servidorDedicat.o: servidorDedicat.c servidorDedicat.h until.h mensaje.h jpg.h
	gcc $(CFLAGS) -c servidorDedicat.c

until.o: until.c until.h
	gcc $(CFLAGS) -c until.c

mensaje.o: mensaje.c mensaje.h
	gcc $(CFLAGS) -c mensaje.c

jpg.o: jpg.c jpg.h
	gcc $(CFLAGS) -c jpg.c

fitxer.o: fitxer.c fitxer.h
	gcc $(CFLAGS) -c fitxer.c

clean:
	rm -f wendy *.o
