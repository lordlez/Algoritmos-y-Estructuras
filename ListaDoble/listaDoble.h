#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(A,B) (((A)<(B)) ? (A) : (B))
#define DUPLICADO -2

typedef struct sNodo{
    void *info;
    struct sNodo *sig, *ant;
    unsigned tamInfo;
}tNodo;

typedef tNodo *tListad;

void crear_lista(tListad *pld);
void vaciar_lista(tListad *pld);
int poner_inicio(tListad *pld, const void *pd, unsigned tam);
int poner_final(tListad *pld, const void *pd, unsigned tam);
int poner_orden(tListad *pld, const void *pd, unsigned tam, int(*cmp)(const void *, const void *));
int primero_lista(const tListad *pld, void *pd, unsigned tam);
int ultimo_lista(const tListad *pld, void *pd, unsigned tam);
int lista_llena(const tListad *pld, unsigned tam);
int lista_vacia(const tListad *pld);

int cmp_enteros(const void *, const void *);

#endif // LISTADOBLE_H