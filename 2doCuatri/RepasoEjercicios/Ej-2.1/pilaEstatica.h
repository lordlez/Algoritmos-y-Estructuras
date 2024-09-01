#ifndef PILAESTATICA_H
#define PILAESTATICA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000
#define MIN(x,y) (((x<y)) ? (x) : (y))

typedef struct{
    char pila[TAM];
    unsigned tope;
}tPila;

void crear_pila(tPila *pp);
void vaciar_pila(tPila *pp);
int apilar(tPila *pp, const void *pd, unsigned tam);
int desapilar(tPila *pp, void *pd, unsigned tam);
int ver_tope(const tPila *pp, void *pd, unsigned tam);
int pila_llena(const tPila *pp, unsigned tam);
int pila_vacia(const tPila *pp);




#endif  // PILAESTATICA_H