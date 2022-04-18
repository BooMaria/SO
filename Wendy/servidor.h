/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Sevidor, este codigo gestiona las peticiones de las estaciones para generar
 * un servidor dedicado.
 */

#ifndef WENDY_SERVIDOR_H
#define WENDY_SERVIDOR_H


#include "fitxer.h"
#include "servidor.h"
#include "servidorDedicat.h"

//Mensajes Error
#define ERROR_BIND              "\nError, Bind."
#define ERROR_MAIN              "\nError, main."
#define ERROR_ARGS              "\nNumero de argumentos incorrecto."


//Mensajes user
#define SERVER_INIT             "\nServer init..."
#define WAIT_CONNECT            "\nWait connect..."
#define CLOSE_SERVER            "\nClose server..."


#define ICP_PRIVATE             1234

#define LISTEN_BACKLOG		20
#define TRUE                1
#define FALSE               0




#endif //WENDY_SERVIDOR_H

