#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(A,B) (((A) < (B)) ? (A) : (B))
#define DUPLICADO -2

typedef struct sNodo{
    void *info;
    struct sNodo *sig;
    unsigned tamInfo;
}tNodo;

typedef tNodo *tLista;


void crear_lista(tLista *pl);
void vaciar_lista(tLista *pl);
int poner_al_inicio(tLista *pl, const void *pd, unsigned tam);
int poner_al_final(tLista *pl, const void *pd, unsigned tam);
int poner_ordenado(tLista *pl, const void *pd, unsigned tam, int (*cmp)(const void *, const void *));
int sacar_al_inicio(tLista *pl, void *pd, unsigned tam);
int sacar_al_final(tLista *pl, void *pd, unsigned tam);
int ver_primero(const tLista *pl, void *pd, unsigned tam);
int ver_ultimo(const tLista *pl, void *pd, unsigned tam);
void ordenar(tLista *pl, int (*cmp)(const void *, const void *));
void recorrer_lista(tLista *pl, void(*mostrar)(void*));
int lista_llena(const tLista *pl, unsigned tam);
int lista_vacia(const tLista *pl);
int buscar_cla_y_eliminar(tLista *pl, void *pd, unsigned tam, int (*cmp)(const void *, const void *));

int cmp_enteros(const void *e1, const void *e2);
void mostrar_lista(void *e);

#endif