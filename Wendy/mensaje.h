/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Codigo mensaje, necesario para la comunicación entre cliente servidor.
 */

#ifndef WENDY_MENSAJE_H
#define WENDY_MENSAJE_H

//Origen
#define ORIGEN_DANNY            "DANNY"
#define ORIGEN_JACK             "JACK"
#define ORIGEN_WENDY            "WENDY"

//Errores propios de mensaje, el usuario que use este codigo deberá hacer el control de errores
#define ERROR_SIZE              "\nError en el tamaño del mensaje."
#define ERROR_ORIGEN            "\nError en el origen de la comunicacion."
#define ERROR_TIPUS             "\nError en el tipo del mensaje."

//Tipus
#define TIPUS_C                 'C' //conecxion
#define TIPUS_D                 'D' //datos
#define TIPUS_B                 'B' //datos correctos
#define TIPUS_K                 'K' //datos incorrectos
#define TIPUS_O                 'O' //comunicacion Ok
#define TIPUS_E                 'E' //Errores
#define TIPUS_Q                 'Q' //desconecxión
#define TIPUS_Z                 'Z' //Error de trama

#define TIPUS_I                 'I' //Info imatge
#define TIPUS_F                 'F' //Imatge bytes
#define TIPUS_S                 'S' //Tot ok
#define TIPUS_R                 'R' //ko
#define TIPUS_M                 'M' //Final Imatge


//Datos preformados
#define MSJ_ERROR                   "ERROR"
#define MSJ_ERROR_TRAMA             "ERROR DE TRAMA"
#define MSJ_CONNECT_OK              "CONNECXIO OK"
#define MSJ_CONNECT_KO              "CONNECXIO KO"
#define MSJ_DADES_OK                "DADES OK"
#define MSJ_DADES_KO                "DADES KO"

#define MSJ_IMATGE_OK               "IMATGE OK"
#define MSJ_IMATGE_KO               "IMATGE KO"

//Tamanys msg
#define SIZEMSG             115
#define SIZEORIGEN          14
#define SIZETIPUS           1
#define SIZEDATA            100

//Començament del apartats
#define STARTCAPSALERA       0
#define STARTIPUS            14
#define STARTDADES           15

typedef struct {
    char origen[SIZEORIGEN];
    char dades[SIZEDATA];
    char tipus;
}Mensaje;

/*
 * Extrae el mensaje de dentro de un array. No se hace control de errores.
 * Pre: El array tiene que tener la medidas correspodiente a los campos establecidos.
 * Post: Copia la información correspondiente en cada uno de los campos del mesaje pasado por parametros.
 */
void MENSAJE_extreure(Mensaje *mensaje, char *msj);

/*
 * Extrae la infomacion en caso de que la info sea una imagen y la pone en dades. No se hace control de erres.
 * Pre: El array tiene que tener la medidas correspodiente a los campos establecidos.
 * Post: Copia toda la informacion que contiene el array en el campo de dades, cuidado
 * esta informacion es binaria no se puede tratar como carcteres.
 */
void MENSAJE_extreureImg(Mensaje *mensaje, char *msj);

/*
 * Crea un mensaje, con el origen tipo y datos que se quiera. No se hace control de errores.
 * Pre: Tanto el origen como tipus son campos preestablecidos estos deberan ser los establecidos en las macros
 * Post: Crea una estructura mensaje que se debera pasar por parametro.
 */
void MENSAJE_crear(Mensaje *mensaje, char *origen, char tipus, char *dades);

/*
 * Crea a partir de un mensaje un array para poder enviar con el formato corresponiente. No se hace control de errores.
 * Pre: El mensaje debe estar bien confeccionado con MENSAJE_crear
 * Post: Retorna un array dinamico con el formato del mensaje a enviar, este array se deberá liberar con free.
 */
char* MENSAJE_envio(Mensaje *dades);

/*
 * Debuger
 */
void MENSAJE_print(Mensaje msj);

//Funciones locales
char* readUntilInfo(char *msj, int inici, int final);


#endif //WENDY_MENSAJE_H
