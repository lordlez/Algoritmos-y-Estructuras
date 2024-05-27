#ifndef ARBOL_H
#define ARBOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMPLETO 1
#define BALANCEADO 2
#define AVL 3
#define DESBALANCEADO 4
#define DUPLICADO -1
#define MIN(A,B)((A<B)?(A):(B))

typedef struct sNodo {
    void *info;
    struct sNodo *izq, *der;
    unsigned tamInfo;
}tNodo;

typedef tNodo *tArbol;

void crear_arbol(tArbol *pa);
void vaciar_arbol(tArbol *pa);
void podar_nivel(tArbol *pa, int n);
void recorrer_orden(const tArbol *pa, void (*accion)(void*, unsigned, void*), void *param);
void recorrer_posorden(const tArbol *pa, void (*accion)(void*, unsigned, void*), void *param);
void recorrer_preorden(const tArbol *pa, void(*accion)(void*, unsigned, void*), void *param);
int contar_nodos(tArbol *pa);
int poner_en_arbol(tArbol *pa, const void *pd, unsigned tam, int (*cmp)(const void*, const void *));
int eliminar_elemento(tArbol *pa, void *pd, unsigned tam, int (*comparar)(const void*, const void*));
int buscar_elemento(const tArbol *pa, void *pd, unsigned tam, int (*comparar)(const void*, const void*));
tNodo **buscar_nodo(const tArbol *pa, const void *pd, int(*comparar)(const void*, const void*));
int eliminar_raiz(tArbol *pa);
int altura(const tArbol *pa);
tNodo **mayor_nodo(const tArbol *pa);
tNodo **menor_nodo(const tArbol *pa);
int tipo_balance(const tArbol *pa);
int arbol_completo(const tArbol *pa);
int arbol_balanceado(const tArbol *pa);
int arbol_avl(const tArbol *pa);
int completo_hasta(const tArbol *pa, int n);


#endif // ARBOL_H