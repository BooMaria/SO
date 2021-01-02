/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Codigo que hace referencia a lo respectivo a la comunicación.
 */

#ifndef DANNY_CONEXIO_H
#define DANNY_CONEXIO_H

//#define     _XOPEN_SOURCE 500
//#define     _POSIX_C_SOURCE 1

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include "jpg.h"
#include "mensaje.h"
#include "until.h"
#include "fitxer.h"


//127.0.0.1 8000


//Errores propios de conexio
#define ERROR_CONEC_JACK                "\nError, no se ha podido conectar con el servidor Jack."
#define ERROR_CONEC_WENDY               "\nError, no se ha podido conectar con el servidor Wendy."
#define ERROR_SOCKET                    "\nError, durante la creacion del socket."
#define ERROR_PROCONEC                  "\nError, en el protocolo de conecxion."

//Mensajes User
#define MSJ_DESCONEC_JACK               "\nDanny se está desconectando de Jack."
#define MSJ_DESCONEC_WENDY              "\nDanny se está desconectando de Wendy."
#define MSJ_CONEC_JACK                  "\nConectando con Jack....."
#define MSJ_CONEC_WENDY                 "\nConectando con Wendy....."
#define MSJ_CONEC_J_OK                  "\nConecxion Jack realizada con exito."
#define MSJ_CONEC_W_OK                  "\nConecxion Wendy realizada con exito."
#define IMG_CORRECTE                    "\nLa imagen ha sido enviada correctamente."
#define IMG_INCORRECTE                  "\nLa imagen no se ha enviado correctamente."

typedef struct{
    char ip[20];
    int port;
    int fd;
}Conexio;

/*
 * Función de conexión con el servidor Jack. Retornara un 1 si la conexión se ha realizado sadisfactoriamente o un 0
 * si no ha sido posible la conexión. Esta funcion utiliza protocolos de comunicación como también hace control
 * de errores.
 * Pre:--
 * Post: Establece un socket con el servidor jack.
 */
int CONEXIO_Jack(Server *thisJack, char *thisNomHost);

/*
 * Función de conexión con el servidor Wendy. Retornara un 1 si la conexión se ha realizado sadisfactoriamente o un 0
 * si no ha sido posible la conexión. Esta funcion utiliza protocolos de comunicación como también hace control
 * de errores.
 * Pre:--
 * Post: Establece un socket con el servidor Wendy.
 */
int CONEXIO_Wendy(Server *thisWendy, char *thiNomHost);

/*
 * Función para enviar un mensaje con datos al servidor Jack. Tiene control de errores.
 * Pre: Info deberá ser una cadena de caracteres bien preformada.
 * Post: Enviara el mensaje, retorna un 1 en caso de que el envió sea sadisfactorio, 0 en el caso contrario.
 */
int CONEXIO_EnviarJack(char *info);

/*
 * Función para enviar un mensaje con una imagen Jpg al servidor Wendy. Tiene control de errores.
 * Pre: La imagen jpg deberá haber sido creada correctamente.
 * Post: Enviara el mensaje, retorna un 1 en caso de que el envió sea sadisfactorio, 0 en el caso contrario.
 */
int CONEXIO_EnviarWendy(Jpg *jpg);

/*
 * Función para deconectar danny del servidor Jack.
 */
void CONEXIO_interruptJack();

/*
 * Función para deconectar danny del servidor Wendy.
 */
void CONEXIO_interruptWendy();

/*
 * Función para saber si danny esta conectado a alguno de los servidores.
 */
int CONEXIO_ON();

//Funcions privades
//Funcion para conectar con un servidor, este retorna el file descriptor para poder comunicarte. Tiene control Errores
int connect_to_server(char *ip, int port);

//PROTOCOLOS COMUNICACIÓN
//Protocolo de Conexion con Jack. Tiene control de errores.
int protocolConexioJack(int fd);

//Protocolo de Conexion con Wendy. Tiene control de errores.
int protocolConexioWendy(int fd);

//Protocolo de transmisión imagen.
int protocolImgRebuda(int fd);

//Protocolo de desconecxion. Tiene control de errores.
void protocolDesconexio(int fd);

//Protocolo de transmision de datos, tiene control de errores.
int protocolDadesRebudes(int fd);

//Protocolo de confimación de recepcion de imagen.
int protocolImgOk(int fd);

#endif //DANNY_CONEXIO_H
