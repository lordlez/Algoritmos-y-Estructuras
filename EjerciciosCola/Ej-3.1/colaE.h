#ifndef COLAE_H
#define COLAE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMCOLA 1000
#define MIN(a,b) ((a) < (b) ? (a):(b))

typedef struct{
    char cola[TAMCOLA];
    unsigned pri, ult, tamDisp;
}tCola;


void crear_cola(tCola *pc);
void vaciar_cola(tCola *pc);
int encolar(tCola *pc, const void *pd, unsigned tam);
int desencolar(tCola *pc, void *pd, unsigned tam);
int ver_primero(const tCola *pc, void *pd, unsigned tam);
int cola_llena(const tCola *pc, unsigned tam);
int cola_vacia(const tCola *pc);

#endif
