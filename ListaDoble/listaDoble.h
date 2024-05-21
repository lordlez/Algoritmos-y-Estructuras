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

typedef tNodo *tListaD;

void crear_lista(tListaD *pld);
void vaciar_lista(tListaD *pld);
int poner_inicio(tListaD *pld, const void *pd, unsigned tam);
int poner_final(tListaD *pld, const void *pd, unsigned tam);
int poner_orden(tListaD *pld, const void *pd, unsigned tam, int (*cmp)(const void *, const void *));
void mostrar_lista(const tListaD *pld, void (*mostrar)(const void *));
int lista_vacia(const tListaD *pld);
int lista_llena(const tListaD *pld, unsigned tam);
void ordenar_lista(tListaD *pld, int (*cmp)(const void *, const void *));
int eliminar_de_ordenada(tListaD *pld, void *pd, unsigned tam, int (*cmp)(const void *, const void *));
int primero(const tListaD *pld, void *pd, unsigned tam);
int ultimo(const tListaD *pld, void *pd, unsigned tam);

#endif // LISTADOBLE_H