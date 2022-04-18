/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Codigo servidorDedicado, crea y gestiona las conexiones propias de uns servidor dedicado.
 */

#include "servidorDedicat.h"

ServidorsDedicat ssDD;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int SERDEDICAT_crea(){
    ssDD.numElements = 0;
    ssDD.conexions = (Conexio **) malloc (sizeof(Conexio *));
    if(ssDD.conexions == NULL){
        write(1, ERROR_MEMORIA, strlen(ERROR_MEMORIA));
        return 0;
    }
    return 1;
}

void SERDEDICAT_destroy(){
    for(int i = 0; i < ssDD.numElements; i++){
        close(ssDD.conexions[i]->fd);
        free(ssDD.conexions[i]);
    }
    free(ssDD.conexions);
    ssDD.numElements = 0;
    pthread_mutex_destroy(&mutex);
}

int SERDEDICAT_run(int fd){
    Conexio *aux;
    aux = (Conexio *) malloc (sizeof(Conexio));
    if(aux == NULL){
        write(1, ERROR_MEMORIA, strlen(ERROR_MEMORIA));
        return 0;
    }else{
        aux->fd = fd;
        if(pthread_create(&(aux->pthread), NULL, runServer, &aux->fd) != 0){
            write(1, ERROR_THREAD, strlen(ERROR_THREAD));
            free(aux);
            return 0;
        }
        if(pthread_detach(aux->pthread)){
            write(1, ERROR_DETACH, strlen(ERROR_DETACH));
            free(aux);
            return 0;
        }
        ssDD.conexions = (Conexio **)realloc((ssDD.conexions), sizeof(Conexio *) * (ssDD.numElements + 1));
        ssDD.conexions[ssDD.numElements] = aux;
        ssDD.numElements++;
    }
    return 1;
}

void SERDEDICAT_close(int thisFd) {
    Conexio *aux;
    char buffer[150] = "";
    int trobat = FALSE;
    int j, i;
    for (i = 0; i < ssDD.numElements; i++) {
        if (ssDD.conexions[i]->fd == thisFd) {
            aux = ssDD.conexions[i];
            trobat = TRUE;
            sprintf(buffer, CLOSE_SERVER_DEDICAT, aux->nomEstacio);
            write(1, buffer, strlen(buffer));
            break;
        }
    }
    for (j = i; j < (ssDD.numElements - 1); j++) {
        ssDD.conexions[j] = ssDD.conexions[j + 1];
    }
    if (trobat) {
        close(aux->fd);
        free(aux);
        ssDD.numElements--;
    }
}

Conexio *SERDEDICAT_getConexio(int fd){
    Conexio *aux = NULL;
    for(int i = 0; i < ssDD.numElements; i++){
        if(ssDD.conexions[i]->fd == fd){
            aux = ssDD.conexions[i];
        }
    }
    return aux;
}

void SERDEDICAT_setNom(int fd, char *nom){
    pthread_mutex_lock(&mutex);
    for(int i = 0; i < ssDD.numElements; i++){
        if(ssDD.conexions[i]->fd == fd){
            strcpy(ssDD.conexions[i]->nomEstacio, nom);
        }
    }
    pthread_mutex_unlock(&mutex);
}

void* runServer(void *arg){
    int sortir = FALSE;
    int fd = *((int*) arg);
    if(protocolConexio(fd)){
        while(!sortir) {
            switch (protocolDades(fd)) {
                case 0:
                    sortir = TRUE;
                    break;
                case 1:
                    break;
                case 2:
                    sortir = TRUE;
                    break;
            }
        }
    }
    pthread_mutex_lock(&mutex);
    SERDEDICAT_close(fd);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int protocolConexio(int fd){
    Mensaje mensaje;
    char bufferRead[150];
    char *bufferWrite;
    int a = read(fd, &bufferRead, SIZEMSG);
    if(a == SIZEMSG){
        MENSAJE_extreure(&mensaje, bufferRead);
        if(strcmp(mensaje.origen, ORIGEN_DANNY) == 0){
            if(mensaje.tipus == TIPUS_C){
                SERDEDICAT_setNom(fd, mensaje.dades);
                sprintf(bufferRead, NEW_CONNECT, mensaje.dades);
                write(1, bufferRead, strlen(bufferRead));
                MENSAJE_crear(&mensaje, ORIGEN_WENDY, TIPUS_O, MSJ_CONNECT_OK);
                bufferWrite = MENSAJE_envio(&mensaje);
                write(fd, bufferWrite, SIZEMSG);
                free(bufferWrite);
                return 1;
            }else{
                write(1, ERROR_TIPUS, strlen(ERROR_TIPUS));
            }
        }else{
            write(1, ERROR_ORIGEN, strlen(ERROR_ORIGEN));
        }
        MENSAJE_crear(&mensaje, ORIGEN_WENDY, TIPUS_E, MSJ_ERROR);
        bufferWrite = MENSAJE_envio(&mensaje);
        write(fd, bufferWrite, SIZEMSG);
        free(bufferWrite);
        return 0;
    }else{
        write(1, ERROR_SIZE, strlen(ERROR_SIZE));
    }
    MENSAJE_crear(&mensaje, ORIGEN_WENDY, TIPUS_Z, MSJ_ERROR_TRAMA);
    bufferWrite = MENSAJE_envio(&mensaje);
    write(fd, bufferWrite, SIZEMSG);
    free(bufferWrite);
    return 0;
}

int protocolDades(int fd){
    Mensaje mensaje;
    Jpg jpg;
    char bufferRead[150];
    char *bufferWrite;
    char *md5;
    int a = read(fd, &bufferRead, SIZEMSG);
    if(a == SIZEMSG){
        MENSAJE_extreure(&mensaje, bufferRead);
        if(strcmp(mensaje.origen, ORIGEN_DANNY) == 0){
            if(mensaje.tipus == TIPUS_I) {
                JPG_setInfo(mensaje.dades, &jpg);

                jpg.imatge = (char *) malloc(sizeof(char) * jpg.size);//Reservam memoria per la imatge
                for (int i = 0; i < (jpg.size + 100); i += 100) {

                    if(!protocolImatge(fd, &jpg, i))return 1;
                }
                FITXER_writeJpg(jpg.nomFitxer, jpg.imatge, jpg.size);

                pthread_mutex_lock(&mutex);//comenta si no chuta
                md5 = JPG_calculMD5(jpg.nomFitxer);//aixo montserrat
                pthread_mutex_unlock(&mutex);

                if (strcmp(md5, jpg.md5sum) == 0) {
                    write(1, IMG_CORRECTE, strlen(IMG_CORRECTE));
                    MENSAJE_crear(&mensaje, ORIGEN_WENDY, TIPUS_S, MSJ_IMATGE_OK);
                    bufferWrite = MENSAJE_envio(&mensaje);
                    write(fd, bufferWrite, SIZEMSG);
                    free(bufferWrite);
                    free(jpg.imatge);
                    free(md5);
                    return 1;
                }
                write(1, IMG_INCORRECTE,strlen(IMG_INCORRECTE));
                MENSAJE_crear(&mensaje, ORIGEN_WENDY, TIPUS_R, MSJ_IMATGE_KO);
                bufferWrite = MENSAJE_envio(&mensaje);
                write(fd, bufferWrite, SIZEMSG);
                free(bufferWrite);
                free(jpg.imatge);
                FITXER_borrarJpg(jpg.nomFitxer);
                free(md5);
                return 1;
            }
            if(mensaje.tipus == TIPUS_Q){
                sprintf(bufferRead, PETICIO_CLOSE, mensaje.dades);
                write(1, bufferRead, strlen(bufferRead));
                return 2;
            }
            write(1, ERROR_TIPUS, strlen(ERROR_TIPUS));
            MENSAJE_crear(&mensaje, ORIGEN_WENDY, TIPUS_S, MSJ_IMATGE_OK);
            bufferWrite = MENSAJE_envio(&mensaje);
            write(fd, bufferWrite, SIZEMSG);
            free(bufferWrite);
            return 0;
        }
        write(1, ERROR_ORIGEN, strlen(ERROR_ORIGEN));
        MENSAJE_crear(&mensaje, ORIGEN_WENDY, TIPUS_K, MSJ_DADES_KO);//cambia protocol error origen i tipus
        bufferWrite = MENSAJE_envio(&mensaje);
        write(fd, bufferWrite, SIZEMSG);
        free(bufferWrite);
        return 0;
    }
    write(1, ERROR_SIZE, strlen(ERROR_SIZE));
    MENSAJE_crear(&mensaje, ORIGEN_WENDY, TIPUS_Z, MSJ_ERROR_TRAMA);
    bufferWrite = MENSAJE_envio(&mensaje);
    write(fd, bufferWrite, SIZEMSG);
    free(bufferWrite);
    return 0;
}

int protocolImatge(int fd, Jpg *jpg, int inici){
    Mensaje mensaje;
    char bufferRead[150];
    char *bufferWrite;
    int a = read(fd, &bufferRead, SIZEMSG);
    if(a == SIZEMSG){
        MENSAJE_extreureImg(&mensaje, bufferRead);
        if(strcmp(mensaje.origen, ORIGEN_DANNY) == 0){
            if(mensaje.tipus == TIPUS_F) {

                JPG_leerImatge(jpg->imatge, mensaje.dades, inici, jpg->size);

                MENSAJE_crear(&mensaje, ORIGEN_WENDY, TIPUS_M, "");//MENSAJE PARA SINCRONIZAR EL ENVIO
                bufferWrite = MENSAJE_envio(&mensaje);
                write(fd, bufferWrite, SIZEMSG);
                free(bufferWrite);
                return 1;
            }
            write(1, ERROR_TIPUS, strlen(ERROR_TIPUS));
        }else{
            write(1, ERROR_ORIGEN, strlen(ERROR_ORIGEN));
        }
        MENSAJE_crear(&mensaje, ORIGEN_WENDY, TIPUS_R, MSJ_IMATGE_KO);
        bufferWrite = MENSAJE_envio(&mensaje);
        write(fd, bufferWrite, SIZEMSG);
        free(bufferWrite);
        return 0;
    }else{
        write(1, ERROR_SIZE, strlen(ERROR_SIZE));
    }
    MENSAJE_crear(&mensaje, ORIGEN_WENDY, TIPUS_Z, MSJ_ERROR_TRAMA);
    bufferWrite = MENSAJE_envio(&mensaje);
    write(fd, bufferWrite, SIZEMSG);
    free(bufferWrite);
    return 0;
}






