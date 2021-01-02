/*
 * autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 */


#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#include "fitxer.h"

void FITXER_readConfig(char const *file, Config *config){
    int fd;
    char *buffer;
    fd = open(file, O_RDONLY);
    if (fd == -1) {
        write( 1 , ERROR_FICHER_CONFIG ,sizeof(ERROR_FICHER_CONFIG));
    }else {
        config->ip = UNTIL_read(fd, '\n');
        buffer = UNTIL_read(fd, '\n');
        config->port = atoi(buffer);
        free(buffer);
        close(fd);
    }
}

void FITXER_writeJpg(char *file, char *img, int size){
    char *path = UNTIL_strCat("Barry/", file);
    int fd = open(path, O_WRONLY|O_CREAT|O_TRUNC, 00666);
    if (fd <= 0) {
        write(1, ERROR_JPG_WRITE, sizeof(ERROR_JPG_WRITE));
    } else {
        write(fd, img, size);
    }
    free(path);
    close(fd);
}

void FITXER_borrarJpg(char *file){
    char *path = UNTIL_strCat("Barry/", file);
    if (remove(path) == 0) {
        write(1, BORRAR_IMAGEN, strlen(BORRAR_IMAGEN));
    }else{
        write( 1 , ERROR_BORRAR_FIT,sizeof(ERROR_BORRAR_FIT));
    }
}