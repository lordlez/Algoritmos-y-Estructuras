#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(A,B) (((A) < (B)) ? (A) : (B))

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

void cargar_pila(tPila *pila, int *num, int ce);
void cargar_ceros(tPila *pila1, tPila *pila2, int diferencia);
void sumar_pilas(tPila *pila1, tPila *pila2, tPila *pilaResultado);
void cargar_vector(tPila *pila, int *vector, int *ce);
void mostrar_vector(int *vector, int ce);




#endif