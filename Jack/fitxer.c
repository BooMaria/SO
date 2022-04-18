/*
 * autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 */

#include "fitxer.h"

void FITXER_writeDades(Llista *l){
    int fd;
    char buffer[150];
    fd = open("Hallorann.txt", O_WRONLY|O_CREAT|O_TRUNC, 00666);
    if (fd == -1) {
        write( 1 , ERROR_FICHER_DADES ,sizeof(ERROR_FICHER_DADES ));
    }else {
        for(int i = 0; i < l->numElements; i++) {
            write(fd, l->llista[i].nom, strlen(l->llista[i].nom));

            sprintf(buffer, "\nTemperatura: %.1f", l->llista[i].temp);
            write(fd, buffer, strlen(buffer));

            sprintf(buffer, "\nHumitat: %d", l->llista[i].humi);
            write(fd, buffer, strlen(buffer));

            sprintf(buffer, "\nPresio: %.1f", l->llista[i].pressio);
            write(fd, buffer, strlen(buffer));

            sprintf(buffer, "\nPrecipitacio: %.1f", l->llista[i].precip);
            write(fd, buffer, strlen(buffer));

            write(fd, "\n", 1);
        }
    }
    close(fd);
}

//funcio que llegeix el fitxer de configuracio
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

