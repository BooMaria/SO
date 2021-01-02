/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Codigo mensaje, necesario para la comunicación entre cliente servidor.
 */

#include "fitxer.h"

void FITXER_readDades(char *directory, char *file, Info *info){
    int fd;
    char *buffer;
    buffer = strcatDinamic(directory, file);
    fd = open(buffer, O_RDONLY);
    if (fd == -1) {
        write( 1 , ERRORFICHERDADES,sizeof(ERRORFICHERDADES));
    }else {
        info->data = UNTIL_read(fd, '\n');
        info->hora = UNTIL_read(fd, '\n');
        info->temp = UNTIL_read(fd, '\n');
        info->hum = UNTIL_read(fd, '\n');
        info->presio = UNTIL_read(fd, '\n');
        info->precip = UNTIL_read(fd, '\n');
        if (remove(buffer) == 0) {
            write(1, BORRAR_FICHERO, strlen(BORRAR_FICHERO));
        }
    }
    free(buffer);
    close(fd);
}

char* FITXER_readJpg(char *file, int *a){
    char c;
    char *img = NULL;
    int i;
    int size = 0;
    int fdR = open(file, O_RDONLY);
    if (fdR == -1) {
        write( 1 , ERRORFICHERIMATGE,sizeof(ERRORFICHERIMATGE));
    }else {
        i = read(fdR, &c, 1);
        while (i > 0){
            size += i;
            img = (char*) realloc(img, sizeof(char) * size);
            img[size - 1] = c;
            i = read(fdR, &c, 1);
        }
        if (remove(file) == 0) {
            write(1, BORRAR_IMAGEN, strlen(BORRAR_IMAGEN));
        }
    }
    close(fdR);
    *a = size;
    return img;
}

void FITXER_readConfig(char const *file, Config *config){
    int fd;
    fd = open(file, O_RDONLY);
    if (fd == -1) {
        write( 1 , ERRORFICHERCONFIG ,sizeof(ERRORFICHERCONFIG));
    }else {
        config->nom = UNTIL_read(fd, '\n');
        config->directori = UNTIL_read(fd, '\n');
        config->temps = UNTIL_read(fd, '\n');
        config->jack.ip = UNTIL_read(fd, '\n');
        config->jack.port = UNTIL_read(fd, '\n');
        config->wendy.ip = UNTIL_read(fd, '\n');
        config->wendy.port = UNTIL_read(fd, '\0');
        close(fd);
    }
}
