/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Codigo, comun para otros, complementa y aporta funcionalidades comunes, como leer de teclado, o extraer
 * información de un array.
 */

#include "until.h"

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

//Lectura destructiva
char* UNTIL_readArray(char* msg, char end){
    int i = 0;
    int j;
    char c;
    char *string = NULL;
    while (TRUE){
        c = msg[0];
        for(j = 1; j < (int)strlen(msg); j++){
            msg[j - 1] = msg[j];
        }
        msg[j - 1] = '\0';
        if (c != end && c != '\0') {
            string = (char*)realloc(string, sizeof(char) * (i + 2));
            string[i++] = c;
        }else {
            i++;
            break;
        }
    }
    string[i - 1] = '\0';
    return string;
}

int UNTIL_strcmpRecursiu(char *a, char *b, int i){
    if(a[i] == '\0' && b[i] == '\0'){
        return TRUE;
    }else{
        if(a[i] != b[i]){
            return FALSE;
        }
        return UNTIL_strcmpRecursiu(a, b, i + 1);
    }
}


