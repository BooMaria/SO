/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Funcionalidad para tratar información binaria, tabajar con una imagen jpg.
 */

#ifndef DANNY_JPG_H
#define DANNY_JPG_H

#include "until.h"
#include "fitxer.h"

//Mensaje error
#define ERRORFICHERIMATGE               "\nError, en la lectura del fichero imagen."
#define ERR_FORK	                    "\nError en la creacion del fork."

//Mensaje user
#define MSJ_CALCULO_MD5             "\n\nEl calculo del MD5 es: "
#define BORRAR_IMAGEN               "\nBorra imagen"

#define WRITE 		1
#define READ  		0

/*
 * Funcion para leer una imagen jpg.
 * Pre: Directorio correcto y file correcto de la jpg que se quiera leer.
 * Post: Actualizara la información de la variable jpg con la imagen leida, esta estructura
 * de datos contendra lo necesario para tratar con la imagen.
 */
void JPG_read(char *directori, char *file, Jpg *jpg);

/*
 * Calculo del checksum de la imagen, mediante un forck se ejecuta una comanda propia de linux para calcula el md5.
 * Pre: Directorio correcto y file correcto de la jpg que se quiera leer.
 * Post: Retorna una cadena de caracteres con el calculo unico de md5.
 */
char* JPG_calculMD5(char *directori, char *file);

#endif //DANNY_JPG_H
