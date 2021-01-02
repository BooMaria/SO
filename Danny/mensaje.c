/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Codigo mensaje, necesario para la comunicación entre cliente servidor.
 */

#include "mensaje.h"

void MENSAJE_extreure(Mensaje *mensaje, char *msj){
    char *info;
    info = readUntilInfo(msj, STARTCAPSALERA, SIZEORIGEN);
    memset(mensaje->origen, '\0', SIZEORIGEN);
    strcpy(mensaje->origen, info);
    free(info);
    mensaje->tipus = msj[STARTIPUS];
    info = readUntilInfo(msj, STARTDADES, SIZEMSG);
    memset(mensaje->dades, '\0', SIZEDATA);
    strcpy(mensaje->dades, info);
    free(info);
}

void MENSAJE_crear(Mensaje *mensaje, char *origen, char tipus, char *dades){
    memset(mensaje->origen, '\0', SIZEORIGEN);
    strcpy(mensaje->origen, origen);
    mensaje->tipus = tipus;
    memset(mensaje->dades, '\0', SIZEDATA);
    strcpy(mensaje->dades, dades);
}

void MENSAJE_setDades(Mensaje *mensaje, int inici, int final, char* img){
    memset(mensaje->dades, '\0', SIZEDATA);
    for(int i = 0; i < SIZEDATA; i++){
        mensaje->dades[i] = img[inici + i];
        if((inici + i) == final) break;
    }
}

char* MENSAJE_envioImagen(Mensaje *dades){
    char *buffer;
    buffer = (char *) malloc(SIZEMSG * sizeof(char));
    int j = 0;
    memset(buffer, '\0', SIZEMSG);
    for(int i = 0; i < (int)strlen(dades->origen); i++){
        buffer[i] = dades->origen[i];
    }
    buffer[STARTIPUS] = dades->tipus;
    for(int i = 0; i < SIZEDATA; i++){
        buffer[i + STARTDADES] = dades->dades[j++];
    }
    return buffer;
}

char* MENSAJE_envio(Mensaje *dades){
    char *buffer = NULL;
    buffer = (char*) malloc(SIZEMSG * sizeof(char));
    int j = 0;
    memset(buffer, '\0', SIZEMSG);
    for(int i = 0; i < (int)strlen(dades->origen); i++){
        buffer[i] = dades->origen[i];
    }
    buffer[STARTIPUS] = dades->tipus;
    for(int i = 0; i < (int)strlen(dades->dades); i++){
        buffer[i + STARTDADES] = dades->dades[j++];
    }
    return buffer;
}

void MENSAJE_print(Mensaje msj){
    write(1,"\n",1);
    write(1, msj.origen, strlen(msj.origen));
    write(1,"\n",1);
    write(1, &msj.tipus, 1);
    write(1,"\n",1);
    write(1, msj.dades, strlen(msj.dades));
    write(1,"\n",1);
}

char* readUntilInfo(char *msj, int inici, int final){
    int i = 0;
    char c ;
    char* string = (char*)malloc(sizeof(char));
    for(int j = inici; j < final; j++){
        c = msj[j];
        if (c != '\0') {
            string = (char*)realloc(string, sizeof(char) * (i + 2));
            string[i++] = c;
        }
    }
    string[i] = '\0';
    return string;
}
