/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Estación meteorologica DANNY.
 */

/*
 * #include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <signal.h>
#include <dirent.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
 */

#define _DEFAULT_SOURCE

#include "fitxer.h"
#include "until.h"
#include "conexio.h"
#include <dirent.h>
#include "jpg.h"

//Mensages Error
#define ERROR_ARGS                  "\nError, Numero de argumentos incorrecto."
#define ERROR_SERVIDORES            "\nError, no se ha podido establecer la comunicación con ningun servidor."
#define ERROR_SCANDIR               "\nError, fallo scandir."

//Mensajes User
#define MSJ_HELLO                   "\nEstacion %s, conectando...\n"
#define NUMDIRECTORI                "\nhi ha %d entrades de directori"
#define STOPDANNY                   "\nParando Danny..."
#define MSJ_COMPROVACION            "\nEstamos en la comprovacion: %d"
#define NO_FILE_AVAILABLE           "\nNo files available..."
#define TESTING                     "\nTesting..."

#define ARGS                2

struct dirent **arxius = NULL;

int numArxius;
int salir = FALSE;

Config config;
Info info;

char buffer[300];

//funcio que allibera espai de memoria
void finalitzaDanny(){
    write(1, STOPDANNY, strlen(STOPDANNY));
    CONEXIO_interruptJack();
    CONEXIO_interruptWendy();
    UNTIL_freeConfig(&config);
    salir = TRUE;
    exit(0);
}

//funcio per tal de poder seleccionar els fitxers del diretori
static int triar (const struct dirent *arg){
    if(strcmp(arg->d_name, ".") == 0 || strcmp(arg->d_name, "..") == 0 || strcmp(arg->d_name, ".DS_Store") == 0){
        return 0;
    }
    return 1;
}

void comprovarFichers(){
    int Ok = TRUE;
    Jpg jpg;
    write(1, TESTING, strlen(TESTING));
    numArxius = scandir (config.directori, &arxius, triar, NULL);
    if(numArxius < 1){
        write(1, NO_FILE_AVAILABLE, strlen(NO_FILE_AVAILABLE));
    }else {
        if (arxius == NULL) {
            write(1, ERROR_SCANDIR, strlen(ERROR_SCANDIR));
            perror("scandir");
            finalitzaDanny();
        }else {
            sprintf(buffer, NUMDIRECTORI, numArxius);
            write(1, buffer, strlen(buffer));
            for (int i = 0; i < numArxius; i++) {
                sprintf(buffer, "\n[%d] %s", i, arxius[i]->d_name);
                write(1, buffer, strlen(buffer));
                if (strstr(arxius[i]->d_name, ".txt") != NULL) {
                    FITXER_readDades(config.directori, arxius[i]->d_name, &info);
                    char *msj = UNTIL_crearMsjDades(&info);
                    Ok = CONEXIO_EnviarJack(msj);
                    free(msj);
                    UNTIL_freeInfo(&info);
                    if (!Ok) {
                        CONEXIO_interruptJack();
                    }
                }
                if (strstr(arxius[i]->d_name, ".jpg") != NULL) {
                    JPG_read(config.directori, arxius[i]->d_name, &jpg);
                    Ok = CONEXIO_EnviarWendy(&jpg);
                    free(jpg.imatge);
                    if (!Ok) {
                        finalitzaDanny();
                        CONEXIO_interruptWendy();
                    }
                }
            }
        }
    }
    alarm(atoi(config.temps));
    signal(SIGALRM, comprovarFichers);
}

int main(int argc, char const *argv[]) {
    int conecJOk;
    int conecWOk;
    if (argc != ARGS) {
        write(1, ERROR_ARGS, sizeof(ERROR_ARGS));
    }else{
        //Reasignamos sigals
        signal(SIGINT, finalitzaDanny);
        signal(SIGALRM, comprovarFichers);
        FITXER_readConfig(argv[1], &config);
        sprintf(buffer, MSJ_HELLO, config.nom);
        write(1, buffer, strlen(buffer));

        conecJOk = CONEXIO_Jack(&config.jack, config.nom);
        conecWOk = CONEXIO_Wendy(&config.wendy, config.nom);

        if(conecJOk || conecWOk){
            alarm(atoi(config.temps));
            int i = 0;
            while(!salir){
                if(!CONEXIO_ON()){
                    finalitzaDanny();
                }
                sprintf(buffer, MSJ_COMPROVACION, i);
                write(1, buffer, strlen(buffer));
                i++;
                pause();
            }
        }else{
            write(1, ERROR_SERVIDORES, strlen(ERROR_SERVIDORES));
        }
    }
    return 0;
}

