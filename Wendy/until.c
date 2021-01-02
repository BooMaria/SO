/*
 * Autors:
 * Maria Aguilà Pons : maria.aguila
 * Xavier Cavaller Allés : xavier.cavaller
 * Data: 17/12/2020
 * Descripció: Codigo, comun para otros, complementa y aporta funcionalidades comunes, como leer de teclado, o extraer
 * información de un array.
 */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "until.h"

int n, m;

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
            string = (char*)realloc(string, sizeof(char) * (i + 1));
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

char* strcatRecursiu(char *dest, char *src, int from){
    if(from >= n - 1) {
        dest[from] = src[from - (n - m)];
        return dest;
    }
    dest[from] = src[from - (n - m)];
    return strcatRecursiu(dest, src, from + 1);
}

char* UNTIL_strCat(char *dest, char *src){
    int from;
    int j;
    m = strlen(src);
    n = strlen(dest);
    char *nouDesti = (char*)malloc(sizeof(char) * (m + n));
    for(from = 0; from < n; from++){
        nouDesti[from] = dest[from];
    }
    for(j = from; j < m+n; j++){
        nouDesti[j] = 'x';
    }
    nouDesti[j] = '\0';
    n = strlen(nouDesti);//actualitza la capacitat del desti
    return strcatRecursiu(nouDesti, src, from);
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
char* UNTIL_itoa(int num){
    char *aux = (char*) malloc (sizeof(char));
    int i = 1;
    itoaReDi(num, aux, i);
    return aux;
}


