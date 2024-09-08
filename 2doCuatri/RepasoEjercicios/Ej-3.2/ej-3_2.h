#ifndef EJ_3_2_H
#define EJ_3_2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(A,B) (((A)<(B)) ? (A) : (B))

typedef struct sNodo{
    void *info;
    struct sNodo *sig;
    unsigned tamInfo;
}tNodo;

typedef struct{
    tNodo *pri;
    tNodo *ult;
}tCola;

void crear_cola(tCola *pc);
void vaciar_cola(tCola *pc);
int encolar(tCola *pc, const void *pd, unsigned tam);
int desencolar(tCola *pc, void *pd, unsigned tam);
int ver_primero(const tCola *pc, void *pd, unsigned tam);
int cola_llena(const tCola *pc, unsigned tam);
int cola_vacia(const tCola *pc);





#endif // EJ_3_2_H