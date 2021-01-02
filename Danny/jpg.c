/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Funcionalidad para tratar información binaria, tabajar con una imagen jpg.
 */

#include "jpg.h"

#define WRITE 		1
#define READ  		0

//const char* md5= "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

char *cmd = "md5sum";
char *argv[3];

void JPG_read(char *directori, char *file, Jpg *jpg){
    char *path = strcatDinamic(directori, file);
    char *md5 = JPG_calculMD5(directori, file);//aixo a montserrat
    strcpy(jpg->nomFitxer, file);
    strcpy(jpg->md5sum, md5);
    jpg->imatge = FITXER_readJpg(path, &(jpg->size));
}

char* JPG_calculMD5(char *directori, char *file){
    char *path = strcatDinamic(directori, file);
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
}


