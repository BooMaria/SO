/*
 * autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 */

#ifndef FASE1_FITXERIN_H
#define FASE1_FITXERIN_H

#include "llistaEstacions.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "servidor.h"

//Mensajes Error
#define ERROR_FICHER_CONFIG             "\nNo es pot obrir el fitxer de configuracio:"
#define ERROR_FICHER_DADES              "\nNo es pot obrir el fitxer de dades:"

//Mensajes User

//Funció que llegeix les dades del fitxer
void FITXER_writeDades(Llista *l);

//Funció que llegeix el fitxer de configuracio
void FITXER_readConfig(char const *file, Config *config);

#endif //FASE1_FITXERIN_H
