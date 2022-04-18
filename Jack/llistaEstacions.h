/*
 Llista Referenciada
 Autor: Xavier Cavaller Allès
 Fecha: 7/10/2020
 Descripcion: Aquesta llista es preten que sigui una llista dinamica la cual es pugui mantenir en una llista tots
 el punter que apuntan a la informació, se ha disenyat pensat amb que una vegada creada sigui facil ordenarla
 no mogent elements o puntes si no posicions, la idea es que l usuari que vulgui utilitza aquesta llista pugui fer un
 array de enters que es pugui ordenar.
*/

#ifndef JACK_LLISTAESTACIONS_H
#define JACK_LLISTAESTACIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "until.h"

typedef struct{
    char nom[30];
    float temp;
    int humi;
    float pressio;
    float precip;
    int num;
}Elemento;

typedef struct{
    int numElements;
    Elemento *llista;//*OKO
}Llista;

Llista LLISTAREFER_crea();

void LLISTAREFER_insereixV2(Llista *l, Elemento e);

void LLISTAREFER_insereix(Llista *l, Elemento e);

Elemento LLISTAREFER_consulta(Llista l, int pos);

int LLISTAREFER_number(Llista *l);

int LLISTAREFER_esborra(Llista *l, int thisId);

void LLISTAREFER_destrueix(Llista *l);

void LLISTAREFER_setDADES(char *dades, Elemento *e, char *nom);

void LLISTAREFER_print(Llista l);

#endif //JACK_LLISTAESTACIONS_H
