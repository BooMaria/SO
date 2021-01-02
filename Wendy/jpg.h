/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Funcionalidad para tratar información binaria
 */

#ifndef WENDY_JPG_H
#define WENDY_JPG_H


//Mensaje error
#define ERRORFICHERIMATGE               "\nError, en la lectura del fichero imagen."
#define ERR_FORK	                    "\nError en la creacion del fork."

//Mensaje user
#define MSJ_CALCULO_MD5                 "\n\nEl calculo del MD5 es: "


#define WRITE 		1
#define READ  		0

typedef struct{
    char nomFitxer[30];
    char md5sum[33];
    int size;
    char *imatge;
}Jpg;

/*
 * Extrae la informacion de un array de caracteres y la introduce en una estructura de datos jpg,
 * con esta información se podra trabajar con la imagen.
 */
void JPG_setInfo(char *dades, Jpg *jpg);

/*
 * Lee una imagen de un array de 100 bytes, esta informacion se va volcando en el array dinamico
 * de jpg imag, este espacio de memoria se debera haber reservado con previamente. La imagen debera ser liberada cuando
 * termine su uso.
 */
void JPG_leerImatge(char* img, char *data, int inici, int fin);

/*
 * Calacula md5 mediante un fork, esta informacion es retornada en forma de array dinamico, debera ser liberado.
 */
char* JPG_calculMD5(char *file);


#endif //WENDY_JPG_H
