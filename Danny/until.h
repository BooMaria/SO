/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Funciones requeridas en diferendes codigos.
 */

#ifndef DANNY_UNTIL_H
#define DANNY_UNTIL_H

//liibreries
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char *data;
    char *hora;
    char *temp;
    char *hum;
    char *presio;
    char *precip;
}Info;

typedef struct{
    char nomFitxer[30];
    char md5sum[33];
    int size;
    char *imatge;
}Jpg;

typedef struct{
    char *ip;
    char *port;
}Server;

typedef struct {
    char *nom;
    char *temps;
    char *directori;
    Server jack;
    Server wendy;
}Config;

/*
 *
 * Pre:
 * Post:
 */
char* UNTIL_crearMsjDades(Info *info);

/*
 *
 * Pre:
 * Post:
 */
char* UNTIL_crearMsjInfoImatge(char *nomFitxer, int size, char *md5);

/*
 * Tipico read para leer informacion de caracteres de un file descriptor, fd file descriptor, end caracter
 * hasta donde se quiere leer, no tiene control de errores.
 * Pre: El fd deberá ser correcto, end debe exitir.
 * Post: Retorna un array dinamico, es responsabilidad del programador que trabaje con está función de liberar la memoria.
 */
char* UNTIL_read(int fd, char end);

/*
 * Libera la memoria de la estructura de datos info.
 * Pre: Info deberá haber sido creada correctamente.
 * Post: Liberará toda la memoria dinamica de la estructura de datos.
 */
void UNTIL_freeInfo(Info *info);

/*
 * Libera la memoria de la estructura de datos config.
 * Pre: Config deberá haber sido creada correctamente.
 * Post: Liberará toda la memoria dinamica de la estructura de datos.
 */
void UNTIL_freeConfig(Config *config);

/*
 * Funciones comunes muy usadas, no tienen control de errores y se debe liberar la memoria.
 * Pre:--
 * Post:--
 */
char* strcatDinamic(char *A, char *B);

/*
 * Itoa, recursiu i memoria dinamica. Aquesta funcio esta formada per dos codis.
 * Pre: El numero te que ser un enter en format integer.
 * Post: Retorna una cadena de carcters amb el numero.
 */
char* itoa(int num);


#endif //DANNY_UNTIL_H
