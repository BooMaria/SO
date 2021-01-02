/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Funciones requeridas en diferendes codigos.
 */

#include "until.h"

char* UNTIL_crearMsjDades(Info *info){
    char *buffer;
    buffer = (char*) malloc(100 * sizeof(char));
    memset(buffer, '\0', 100);
    strcat(buffer, info->data);
    strcat(buffer, "#");
    strcat(buffer, info->hora);
    strcat(buffer, "#");
    strcat(buffer, info->temp);
    strcat(buffer, "#");
    strcat(buffer, info->hum);
    strcat(buffer, "#");
    strcat(buffer, info->presio);
    strcat(buffer, "#");
    strcat(buffer, info->precip);
    return buffer;
}

char* UNTIL_crearMsjInfoImatge(char *nomFitxer, int size, char *md5){
    char *buffer;
    buffer = (char*) malloc(100 * sizeof(char));
    memset(buffer, '\0', 100);
    strcat(buffer, nomFitxer);
    strcat(buffer, "#");
    char *aux = itoa(size);
    strcat(buffer, aux);
    free(aux);
    strcat(buffer, "#");
    strcat(buffer, md5);
    return buffer;
}

//funcio utilitzada per llegir de fitxer fins a un determinar caracter
char* UNTIL_read(int fd, char end) {
    int i = 0, size;
    char c = '\0';
    char* string = (char*)malloc(sizeof(char));
    while (1) {
        size = read(fd, &c, sizeof(char));
        if (c != end && size > 0 && c != '\0') {
            string = (char*)realloc(string, sizeof(char) * (i + 2));
            string[i++] = c;
        } else {
            i++; //Pel \0
            break;
        }
    }
    string[i - 1] = '\0';
    return string;
}

void UNTIL_freeInfo(Info *info){
    free(info->data);
    free(info->hora);
    free(info->temp);
    free(info->hum);
    free(info->presio);
    free(info->precip);
}

void UNTIL_freeConfig(Config *config){
    free(config->nom);
    free(config->temps);
    free(config->directori);
    free(config->jack.ip);
    free(config->jack.port);
    free(config->wendy.ip);
    free(config->wendy.port);
}

char* strcatDinamic(char *A, char *B){//
    char* complet = (char*) malloc (sizeof(char)* (strlen(A) + strlen(B) + 1));
    int i, j;
    for(i = 0; i < (int)strlen(A); i++){
        complet[i] = A[i];
    }
    for(j = 0; j < (int)strlen(B); j++){
        complet[i + j] = B[j];
    }
    complet[i + j] = '\0';
    return complet;
}

int itoaReDi(int num, char *resposta, int i){
    if(num < 10){
        resposta = (char*) realloc(resposta, sizeof(char) * i + 1);
        resposta[0] = (char)('0' + num);
        resposta[i] = '\0';
        return 0;
    }else{
        int j = itoaReDi(num / 10, resposta, ++i);
        j++;
        resposta[j] = (char)((num % 10) + '0');
        if(i != 1) return j;
    }
    return 1;
}
char* itoa(int num){
    char *aux = (char*) malloc (sizeof(char));
    int i = 1;
    itoaReDi(num, aux, i);
    return aux;
}




