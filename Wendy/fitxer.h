/*
 * autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 */

#ifndef WENDY_FITXER_H
#define WENDY_FITXER_H

#include "until.h"
#include "servidor.h"


//Mensajes Error
#define ERROR_FICHER_CONFIG             "\nNo es pot obrir el fitxer de configuracio:"
#define ERROR_JPG_WRITE                 "\nError, en la escritura fichero de una imagen JPG."
#define ERROR_BORRAR_FIT                "\nError, en borrado fichero imagen."

//Mensajes Usuario
#define BORRAR_IMAGEN                   "\nFichero borrado"

//Funció que llegeix el fitxer de configuracio
void FITXER_readConfig(char const *file, Config *config);

//Funció per llegir una imatge jpg.
void FITXER_writeJpg(char *file, char *imatge, int size);

//Funció que borra una imatge jpg.
void FITXER_borrarJpg(char *path);

#endif //WENDY_FITXER_H
