#ifndef ARBOLCB_H_INCLUDED
#define ARBOLCB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DUPLICADO -2

typedef struct sNodo{
    void *info;
    struct sNodo *izq, *der;
    unsigned tamInfo;
}tNodo;

typedef tNodo *tArbol;

void crear_arbol(tArbol *pa);
int poner_arbol(tArbol *pa, const void *pd, unsigned tam, int (*cmp)(const void*, const void*));
void recorrer_preorden(const tArbol *pa, void(*accion)(void*, unsigned, void*), void *param);
void recorrer_orden(const tArbol *pa, void(*accion)(void*, unsigned, void*), void *param);
void recorrer_posorden(const tArbol *pa, void(*accion)(void*, unsigned, void*), void *param);
int cmp_enteros(const void *e1, const void *e2);

void imprimir_arbol_horizontal(const tArbol *pa, int espacio);
void imprimir_nodo(void *info, unsigned tam, void *param);

#endif // ARBOLCB_H_INCLUDED
