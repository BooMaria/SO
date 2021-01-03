/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Funcionalidad para tratar información binaria
 */


#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "until.h"
#include "jpg.h"

//const char* md5= "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

char *cmd = "md5sum";
char *argv[3];


void JPG_setInfo(char *dades, Jpg *jpg){
    char *buffer;
    buffer = UNTIL_readArray(dades, '#');
    strcpy(jpg->nomFitxer, buffer);
    free(buffer);
    buffer = UNTIL_readArray(dades, '#');//paso de la hora//aqui lee un 1 de mas
    jpg->size = atoi(buffer);
    free(buffer);
    buffer = UNTIL_readArray(dades, '\0');
    strcpy(jpg->md5sum, buffer);
    free(buffer);
}

void JPG_leerImatge(char* img, char *data, int inici, int fin){
    int size = inici;
    for(int i = 0; i < 100; i++){
        img[size++] = data[i];
        if(size == fin)break;
    }
}

char* JPG_calculMD5(char *file){
    char *path = UNTIL_strCat("Barry/", file);
    int pipeRead[2];
    char *resultat = NULL;
    pipe(pipeRead);
    argv[0] = "md5sum";
    argv[1] = path;
    argv[2] = NULL;
    pid_t pid = fork();
    switch (pid) {
        case -1:
            close(pipeRead[READ]);
            close(pipeRead[WRITE]);
            write(1, ERR_FORK, strlen(ERR_FORK));
            break;
        case 0://fill
            close(pipeRead[READ]);
            dup2(pipeRead[WRITE], 1);
            execvp(cmd, argv);
            //free(path);
            exit(0);
        default://pare
            close(pipeRead[WRITE]);
            resultat = UNTIL_read(pipeRead[READ], ' ');
            write(1,MSJ_CALCULO_MD5, strlen(MSJ_CALCULO_MD5));
            write(1, resultat, strlen(resultat));
            write(1,"\n", 1);
            close(pipeRead[READ]);
            break;
    }
    return resultat;
    //return md5;
}


