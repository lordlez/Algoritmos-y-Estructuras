#ifndef PILADINAMICA_H
#define PILADINAMICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) (((x<y)) ? (x) : (y))

typedef struct sNodo{
    void *info;
    struct sNodo *sig;
    unsigned tamInfo;
}tNodo;

typedef tNodo *tPila;

void crear_pila(tPila *pp);
void vaciar_pila(tPila *pp);
int apilar(tPila *pp, const void *pd, unsigned tam);
int desapilar(tPila *pp, void *pd, unsigned tam);
int ver_tope(const tPila *pp, void *pd, unsigned tam);
int pila_llena(const tPila *pp, unsigned tam);
int pila_vacia(const tPila *pp);




#endif // PILADINAMICA_H