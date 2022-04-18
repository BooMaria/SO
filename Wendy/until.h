/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Funciones requeridas en diferendes codigos.
 */

#ifndef WENDY_UNTIL_H
#define WENDY_UNTIL_H


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

/*
 * strcat recursiu i dinamic.
 * Pre: --
 * Post: --
 * no libera memoria
 */
char* UNTIL_strCat(char *dest, char *src);

/*
 * Itoa, recursiu i memoria dinamica. Aquesta funcio esta formada per dos codis.
 * Pre: El numero te que ser un enter en format integer.
 * Post: Retorna una cadena de carcters amb el numero.
 */
char* UNTIL_itoa(int num);


#endif //WENDY_UNTIL_H
