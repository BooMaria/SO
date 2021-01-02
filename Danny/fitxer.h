/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Codigo mensaje, necesario para la comunicación entre cliente servidor.
 */

#ifndef FASE1_FITXERIN_H
#define FASE1_FITXERIN_H

#include "conexio.h"
#include "until.h"

#define ERRORFICHERDADES            "\nNo es pot obrir el fitxer de dades:"
#define ERRORFICHERCONFIG           "\nNo es pot obrir el fitxer de configuracio:"
#define ERROR_JPG_READ              "\nError, en la lectura fichero de una imagen JPG."
#define ERROR_JPG_WRITE             "\nError, en la escritura fichero de una imagen JPG"

#define BORRAR_FICHERO              "\nFichero borrado"

/*
 * Lectura de un fichero de texto. tiene control de errores propios.
 * Pre: --
 * Post: Llenara la variable info con la información leida del fichero de texto, despues borrará
 * el fichero.
 */
void FITXER_readDades(char *directory, char *file, Info *info);

/*
 * Lectura de un JPG, en este caso retornara un puntero a una regi.
 * Pre: --
 * Post: La función retornara un puntero donde se encotrara la imagen como información binaria. La variable a
 * sera actualizada al valor del tamaño en bytes del fichero. La imagen deberá ser liberada.
 */
char* FITXER_readJpg(char *file, int *a);

/*
 * Función para leer un fichero donde se encontrara la configuración de la estación Danny como también lo necesario
 * para conectarse a los servidores.
 * Pre: --
 * Post: Actualizara la informacion de la variable config con los parametro leidos.
 */
void FITXER_readConfig(char const *file, Config *config);

#endif //FASE1_FITXERIN_H
