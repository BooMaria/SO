/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Sevidor, este codigo gestiona las peticiones de las estaciones para generar
 * un servidor dedicado.
 */

#ifndef JACK_SERVIDOR_H
#define JACK_SERVIDOR_H

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "llistaEstacions.h"
#include "servidorDedicat.h"
#include "fitxer.h"

//Mensajes Error
#define ERROR_SOCKET            "\nError, Socket"
#define ERROR_BIND              "\nError, Bind."
#define ERROR_MAIN              "\nError, main."
#define ERROR_FORK              "\nError, fork."
#define ERROR_MEMO_COMP         "\nError, memoria compartida."
#define ERROR_ARGS              "\nNumero de argumentos incorrecto."


//Mensajes user
#define SERVER_INIT             "\nServer init..."
#define LLOYD_INIT              "\nLloyd init..."
#define WAIT_CONNECT            "\nWait connect..."
#define CLOSE_SERVER            "\nServer close..."
#define CLOSE_LLOYD             "\nLloyd close..."


#define LISTEN_BACKLOG		20
#define TRUE                1
#define FALSE               0

#define ARGS                2

void dadesNoves(char *nom, char *info);

#endif //JACK_SERVIDOR_H
