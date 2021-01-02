/*
 Llista Referenciada
 Autor: Xavier Cavaller Allès
 Fecha: 7/10/2020
 Descripcion: Aquesta llista es preten que sigui una llista dinamica la cual es pugui mantenir en una llista tots
 el punter que apuntan a la informació, se ha disenyat pensat amb que una vegada creada sigui facil ordenarla
 no mogent elements o puntes si no posicions, la idea es que l usuari que vulgui utilitza aquesta llista pugui fer un
 array de enters que es pugui ordenar.
*/

#include "llistaEstacions.h"

Llista LLISTAREFER_crea(){
    Llista l;
    l.numElements = 0;
    l.llista = (Elemento **) malloc (sizeof(Elemento*));
    if(l.llista == NULL){
        printf("\nError en reserva de memoria!\n");
    }
    return l;
}

void LLISTAREFER_insereixV2(Llista *l, Elemento e){
    int trobat = FALSE;
    for(int i = 0; i < l->numElements; i++){
        if(strcmp(l->llista[i]->nom, e.nom) == 0){
            l->llista[i]->humi = ((l->llista[i]->humi * l->llista[i]->num) + e.humi)/(l->llista[i]->num + 1);
            l->llista[i]->pressio = ((l->llista[i]->pressio * l->llista[i]->num) + e.pressio)/(float)(l->llista[i]->num + 1);
            l->llista[i]->precip = ((l->llista[i]->precip * l->llista[i]->num) + e.precip)/(float)(l->llista[i]->num + 1);
            l->llista[i]->temp= ((l->llista[i]->temp * l->llista[i]->num) + e.temp)/(float)(l->llista[i]->num + 1);
            (l->llista[i]->num)++;
            trobat = TRUE;
        }
    }
    if(!trobat){
        LLISTAREFER_insereix(l, e);
    }
}

void LLISTAREFER_insereix(Llista *l, Elemento e){
    Elemento *aux;
    aux = (Elemento *) malloc (sizeof(Elemento));
    if(aux == NULL){
        printf("\nError en reserva de memoria!\n");
    }else{
        l->llista = (Elemento**)realloc((l->llista), sizeof(Elemento*) * (l->numElements + 1));
        *aux = e;
        l->llista[l->numElements] = aux;
        l->llista[l->numElements]->num = 1;
        l->numElements++;
        free(aux);
    }
}

Elemento LLISTAREFER_consulta(Llista l, int pos){
    Elemento e;
    if(pos < l.numElements){
        e = *(l.llista[pos]);
    }
    return e;
}

int LLISTAREFER_number(Llista *l){
    return l->numElements;
}

int LLISTAREFER_esborra(Llista *l, int thisId) {
    Elemento *aux;
    int trobat = FALSE;
    int j, i;
    for (i = 0; i < l->numElements; i++) {
        if (l->llista[i]->num == thisId) {
            aux = l->llista[i];
            trobat = TRUE;
            free(aux); // es possible
            break;
        }
    }
    for (j = i; j < (l->numElements - 1); j++) {
        l->llista[j] = l->llista[j + 1];
    }
    if (trobat) {
        free(aux);
        l->llista[j + 1] = NULL;
        l->numElements--;
        return 1;
    }
    return -1;
}

void LLISTAREFER_destrueix(Llista *l){
    for(int i = 0; i < l->numElements; i++){
        free(l->llista[i]);
        l->llista[i] = NULL;
    }
    l->llista = NULL;
}

void LLISTAREFER_setDADES(char *dades, Elemento *e, char *nom){
    char *buffer;
    strcpy(e->nom, nom);
    buffer = UNTIL_readArray(dades, '#');//paso de la fecha
    free(buffer);
    buffer = UNTIL_readArray(dades, '#');//paso de la hora
    free(buffer);
    buffer = UNTIL_readArray(dades, '#');
    e->temp = atof(buffer);
    free(buffer);
    buffer = UNTIL_readArray(dades, '#');
    e->humi = atoi(buffer);
    free(buffer);
    buffer = UNTIL_readArray(dades, '#');
    e->pressio = atof(buffer);
    free(buffer);
    buffer = UNTIL_readArray(dades, '\0');
    e->precip = atof(buffer);
    free(buffer);
}

void LLISTAREFER_print(Llista l){
    char buffer[200];
    for(int i = 0; i < l.numElements; i++){
        sprintf(buffer, "\nnom: %s, temp: %.2f, precip: %.2f, precio: %.2f, humitat: %d", l.llista[i]->nom,
                l.llista[i]->temp, l.llista[i]->precip, l.llista[i]->pressio, l.llista[i]->humi);
        write(1, buffer, strlen(buffer));
    }
}
