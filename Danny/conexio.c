/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Codigo que hace referencia a lo respectivo a la comunicacion.
 */

#include "conexio.h"

Conexio conexWendy;
Conexio conexJack;

int CONEXIO_Jack(Server *jack, char *thisNomHost){
    Mensaje mensaje;
    char *buffer;
    write(1, MSJ_CONEC_JACK, strlen(MSJ_CONEC_JACK));
    strcpy(conexJack.ip, jack->ip);
    conexJack.port = atoi(jack->port);
    conexJack.fd = connect_to_server(conexJack.ip, conexJack.port);
    if(conexJack.fd < 0){
        write(1, ERROR_CONEC_JACK, strlen(ERROR_CONEC_JACK));
        return 0;
    }
    MENSAJE_crear(&mensaje, ORIGEN_DANNY, TIPUS_C, thisNomHost);
    buffer = MENSAJE_envio(&mensaje);
    write(conexJack.fd, buffer, SIZEMSG);
    free(buffer);
    if(protocolConexioJack(conexJack.fd)) {
        write(1, MSJ_CONEC_J_OK, strlen(MSJ_CONEC_J_OK));
        return 1;
    }else {
        write(1, ERROR_PROCONEC, strlen(ERROR_PROCONEC));
        return 0;
    }
}

int CONEXIO_Wendy(Server *wendy, char *thisNomHost){
    Mensaje mensaje;
    char *buffer;
    write(1, MSJ_CONEC_WENDY, strlen(MSJ_CONEC_WENDY));
    strcpy(conexWendy.ip, wendy->ip);
    conexWendy.port = atoi(wendy->port);
    conexWendy.fd = connect_to_server(conexWendy.ip, conexWendy.port);
    if(conexWendy.fd < 0){
        write(1, ERROR_CONEC_WENDY, strlen(ERROR_CONEC_WENDY));
        return 0;
    }
    MENSAJE_crear(&mensaje, ORIGEN_DANNY, TIPUS_C, thisNomHost);
    buffer = MENSAJE_envio(&mensaje);
    write(conexWendy.fd, buffer, SIZEMSG);
    free(buffer);
    if(protocolConexioWendy(conexWendy.fd)) {
        write(1, MSJ_CONEC_W_OK, strlen(MSJ_CONEC_W_OK));
        return 1;
    }else {
        write(1, ERROR_PROCONEC, strlen(ERROR_PROCONEC));
        return 0;
    }
}

int CONEXIO_EnviarJack(char *info){
    Mensaje mensaje;
    char *buffer;
    MENSAJE_crear(&mensaje, ORIGEN_DANNY, TIPUS_D, info);
    buffer = MENSAJE_envio(&mensaje);
    write(conexJack.fd, buffer, SIZEMSG);
    free(buffer);
    return protocolDadesRebudes(conexJack.fd);
}

int CONEXIO_EnviarWendy(Jpg *jpg){
    Mensaje mensaje;
    char *buffer;
    buffer = UNTIL_crearMsjInfoImatge(jpg->nomFitxer, jpg->size, jpg->md5sum);
    MENSAJE_crear(&mensaje, ORIGEN_DANNY, TIPUS_I, buffer);
    free(buffer);
    buffer = MENSAJE_envio(&mensaje);
    write(conexWendy.fd, buffer, SIZEMSG);
    free(buffer);
    MENSAJE_crear(&mensaje, ORIGEN_DANNY, TIPUS_F, "");
    for(int i = 0; i < (jpg->size +100); i += 100){
        MENSAJE_setDades(&mensaje, i, jpg->size, jpg->imatge);
        buffer = MENSAJE_envioImagen(&mensaje);
        write(conexWendy.fd, buffer, SIZEMSG);
        free(buffer);
        if(!protocolImgRebuda(conexWendy.fd)) return 1;
    }
    if(!protocolImgOk(conexWendy.fd)) return 1;
    return 1;
}

void CONEXIO_interruptJack() {
    if (conexJack.fd != -1) {
        write(1, MSJ_DESCONEC_JACK, strlen(MSJ_DESCONEC_JACK));
        protocolDesconexio(conexJack.fd);
        close(conexJack.fd);
        conexJack.fd = -1;
    }
}

void CONEXIO_interruptWendy(){
    if (conexWendy.fd != -1) {
        write(1, MSJ_DESCONEC_WENDY, strlen(MSJ_DESCONEC_WENDY));
        protocolDesconexio(conexWendy.fd);
        close(conexWendy.fd);
        conexWendy.fd = -1;
    }
}

int CONEXIO_ON(){
    if(conexWendy.fd == -1 && conexJack.fd == -1) {
        return 0;
    }
    return 1;
}

int connect_to_server(char *ip, int port) {
    struct sockaddr_in s_addr;
    int socket_conn = -1;
    socket_conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_conn < 0) write(1, ERROR_SOCKET, sizeof(ERROR_SOCKET));
    else {
        memset(&s_addr, 0, sizeof(s_addr));
        s_addr.sin_family   = AF_INET;
        s_addr.sin_port     = htons(port);
        s_addr.sin_addr.s_addr = inet_addr(ip);
        if (connect(socket_conn, (void *) &s_addr, sizeof(s_addr)) < 0) {
            close(socket_conn);
            socket_conn = -1;
        }
    }
    return socket_conn;
}

int protocolConexioJack(int fd){
    Mensaje mensaje;
    char bufferRead[150];
    int a = read(fd, &bufferRead, 150);
    if(a == SIZEMSG){
        MENSAJE_extreure(&mensaje, bufferRead);
        if(strcmp(mensaje.origen, ORIGEN_JACK) == 0){
            if(mensaje.tipus == 'O'){
                if(strcmp(mensaje.dades, "CONNECXIO OK") == 0){
                    return 1;
                }else{
                    return 0;
                }
            }else{
                write(1, ERROR_TIPUS, strlen(ERROR_TIPUS));
            }
        }else{
            write(1, ERROR_ORIGEN, strlen(ERROR_ORIGEN));
        }
    }else{
        write(1, ERROR_SIZE, strlen(ERROR_SIZE));
    }
    return 0;
}

int protocolConexioWendy(int fd){
    Mensaje mensaje;
    char bufferRead[150];
    int a = read(fd, &bufferRead, 150);
    if(a == SIZEMSG){
        MENSAJE_extreure(&mensaje, bufferRead);
        if(strcmp(mensaje.origen, ORIGEN_WENDY) == 0){
            if(mensaje.tipus == 'O'){
                if(strcmp(mensaje.dades, "CONNECXIO OK") == 0){
                    return 1;
                }else{
                    return 0;
                }
            }else{
                write(1, ERROR_TIPUS, strlen(ERROR_TIPUS));
            }
        }else{
            write(1, ERROR_ORIGEN, strlen(ERROR_ORIGEN));
        }
    }else{
        write(1, ERROR_SIZE, strlen(ERROR_SIZE));
    }
    return 0;
}

int protocolImgRebuda(int fd){
    Mensaje mensaje;
    char bufferRead[150];
    int a = read(fd, &bufferRead, 150);
    if(a == SIZEMSG){
        MENSAJE_extreure(&mensaje, bufferRead);
        if(strcmp(mensaje.origen, ORIGEN_WENDY) == 0){
            if(mensaje.tipus == TIPUS_M){
                return 1;
            }else{
                write(1, ERROR_TIPUS, strlen(ERROR_TIPUS));
            }
        }else{
            write(1, ERROR_ORIGEN, strlen(ERROR_ORIGEN));
        }
    }else{
        write(1, ERROR_SIZE, strlen(ERROR_SIZE));
    }
    write(1, IMG_INCORRECTE, strlen(IMG_INCORRECTE));
    return 0;
}

int protocolImgOk(int fd){
    Mensaje mensaje;
    char bufferRead[150];
    int a = read(fd, &bufferRead, 150);
    if(a == SIZEMSG){
        MENSAJE_extreure(&mensaje, bufferRead);
        if(strcmp(mensaje.origen, ORIGEN_WENDY) == 0){
            if(mensaje.tipus == TIPUS_S) {
                write(1, IMG_CORRECTE, strlen(IMG_CORRECTE));
                return 1;
            }
            if(mensaje.tipus == TIPUS_R){
                write(1, IMG_INCORRECTE, strlen(IMG_INCORRECTE));
                return 0;
            }
            write(1, ERROR_TIPUS, strlen(ERROR_TIPUS));
        }else{
            write(1, ERROR_ORIGEN, strlen(ERROR_ORIGEN));
        }
    }else{
        write(1, ERROR_SIZE, strlen(ERROR_SIZE));
    }
    return 0;
}

int protocolDadesRebudes(int fd){
    Mensaje mensaje;
    char bufferRead[150];
    int a = read(fd, &bufferRead, 150);
    if(a == SIZEMSG){
        MENSAJE_extreure(&mensaje, bufferRead);
        if(strcmp(mensaje.origen, ORIGEN_JACK) == 0){
            if(mensaje.tipus == TIPUS_B){
                if(strcmp(mensaje.dades, MSJ_DADES_OK) == 0){
                    return 1;
                }
            }
            if(mensaje.tipus == TIPUS_K){
                write(1, ERROR_TRANSMISION, strlen(ERROR_TRANSMISION));
                return 0;
            }
            write(1, ERROR_TIPUS, strlen(ERROR_TIPUS));
        }else{
            write(1, ERROR_ORIGEN, strlen(ERROR_ORIGEN));
        }
    }else{
        write(1, ERROR_SIZE, strlen(ERROR_SIZE));
    }
    return 0;
}

void protocolDesconexio(int fd){
    Mensaje mensaje;
    char *buffer;
    MENSAJE_crear(&mensaje, ORIGEN_DANNY, TIPUS_Q, "");
    buffer = MENSAJE_envio(&mensaje);
    write(fd, buffer, SIZEMSG);
    free(buffer);
}




