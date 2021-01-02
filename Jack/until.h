//
// Created by Xavier Cavaller Alles on 22/11/2020.
//

#ifndef JACK_UNTIL_H
#define JACK_UNTIL_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define TRUE                1
#define FALSE               0

typedef struct {
    char *ip;
    int  port;
}Config;

/*
 * Lectura de un file descriptor. No tiene control de errores.
 * Pre: El file descriptor debe ser correcto, end sera un caracter asta donde se quiera leer.
 * Post: Retorna un array dinamico con la info leida, se debera liberar.
 */
char* UNTIL_read(int fd, char end);

/*
 * Lectura de un Array hasta un caracter especifico, la lectura es destructiva. No tiene control de errores.
 * Pre: --
 * Post: Retorna un array dinamico con la info leida, se debera liberar. El array de entrada lo llena con \0,
 * no libera memoria
 */
char* UNTIL_readArray(char* msg, char end);

/*
 * Strcad recursivo.
 * Pre: --
 * Post: --
 */
int UNTIL_strcmpRecursiu(char *a, char *b, int i);

#endif //JACK_UNTIL_H
