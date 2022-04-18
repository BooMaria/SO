CFLAGS=-Wall -Wextra -lpthread

all: servidor

servidor: servidor.o servidorDedicat.o until.o mensaje.o llistaEstacions.o fitxer.o
	gcc -o jack servidor.o servidorDedicat.o until.o mensaje.o llistaEstacions.o fitxer.o -pthread

servidor.o: servidor.c servidorDedicat.h servidorDedicat.h until.h mensaje.h llistaEstacions.h semaphore_v2.h fitxer.h
	gcc $(CFLAGS) -c servidor.c

servidorDedicat.o: servidorDedicat.c servidorDedicat.h until.h mensaje.h
	gcc $(CFLAGS) -c servidorDedicat.c

until.o: until.c until.h
	gcc $(CFLAGS) -c until.c

mensaje.o: mensaje.c mensaje.h
	gcc $(CFLAGS) -c mensaje.c

llistaEstacions.o: llistaEstacions.c llistaEstacions.h
	gcc $(CFLAGS) -c llistaEstacions.c

fitxer.o: fitxer.c fitxer.h
	gcc $(CFLAGS) -c fitxer.c

clean:
	rm -f jack *.o
