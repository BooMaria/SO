/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Codigo servidorDedicado, crea y gestiona las conexiones propias de uns servidor dedicado.
 */

#ifndef SERVIDORDEDICAT_SERVIDORDEDICAT_H
#define SERVIDORDEDICAT_SERVIDORDEDICAT_H


#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "llistaEstacions.h"
#include "servidor.h"
#include "mensaje.h"

//Mensajes Error
#define ERROR_THREAD            "\nError, crear thread!"
#define ERROR_MEMORIA           "\nError, en reserva de memoria!"
#define ERROR_DETACH            "\nError, en el Deatach!"

//Mensajes user
#define PETICIO_CLOSE           "\nPeticion close: %s"
#define CLOSE_SERVERDEDICAT     "\nClose server dedicat: %s"
#define NEW_CONNECT             "\nNew connect: %s"

//Otras Macros
#define LISTEN_BACKLOG		20

typedef struct{
    pthread_t pthread;      //identificador del thread
    int fd;                 //file descriptor de comunicacion
    char nomEstacio[100];    //Nom de la estacio
}Conexio;

typedef struct{
    int numElements;
    Conexio **conexions;
}ServidorsDedicat;

/*
 * Crea una lista autogestionada de servidores dedicados.
 * Pre: -
 * Post: Inicializa la lista de clientes. Retorna 1 si a sido posible, 0 si no.
 * Gestion Errores: Gestiona error de reserva de memoria.
 */
int SERDEDICAT_crea();

/*
 * Libera toda la memoria,
 * Pre: Se debe haver creado con SERDEDICAT_crea().
 * Post: Destruye por completo la lista de servidores.
 */
void SERDEDICAT_destroy();

/*
 * Pone en marcha una conexion con un clinte a partir de un file descriptor, este file descriptor
 * funcionara a su vez como id del servidor.
 * Pre: El servidor debe estar inicializado con la funcion crea.
 * Post: Ejecutara un thread con el objetivo de mantener la comunicación con un cliente. Retorna 1 si a sido posible, 0 si no.
 * Gestion Errores: Control de errores en thread y en reserva de memoria.
 */
int SERDEDICAT_run(int fd);

/*
 * Cierra la conexion y libera la memoria de la conexion. No tiene control de errores
 * Pre: La conexion se debe haber establecido correctamente.
 * Post: Cerrara la conexion.
 */
void SERDEDICAT_close(int thisFd);

/*
 * Retorna un puntero donde se encuentra la informacion del servidor.
 * Pre: El fd debe pertenecer a uno de los servidores activos.
 * Post: Retornara un puntero de la informacion.
 * Gestion Errores: Control de errores en thread y en reserva de memoria.
 */
Conexio *SERDEDICAT_getConexio(int fd);

/*
 * Copia el nombre en la estructura de datos perteneciente al servidor dedicado. No tiene control de errores
 * Pre: El fd debe pertenecer a uno de los servidores activos.
 * Post: Copia el nombre en la estructura de datos.
 */
void SERDEDICAT_setNom(int fd, char *nom);

/*
 * Debuger
 */
void SERDEDICAT_print();

//Funcions privadas del codigo

//Funcion ejecutada por thread
void* runServer(void *arg);

//Protocolo conexion. Control de errores
int protocolConexio(int fd);

//Protocola comunicacion de datos. Control de errores
int protocolDades(int fd);

#endif //SERVIDORDEDICAT_SERVIDORDEDICAT_H
