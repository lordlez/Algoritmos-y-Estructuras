#ifndef TDALISTACIRCULAR_H_INCLUDED
#define TDALISTACIRCULAR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN(X,Y) ((X)<(Y)?(X):(Y))

#define SIN_MEM 0
#define VACIA 0

#define OK 1

typedef struct sNodo{
    void* info;
    unsigned tamInfo;
    struct sNodo *ste;
}tNodo;

typedef tNodo* tLista;

void crearLista(tLista *pl);
void vaciarLista(tLista *pl);

int Insertar(tLista *pl, const void *pd, unsigned cantBytes);
int VerPrimero(const tLista* pl, void *pd, unsigned cantBytes);
int Sacar(tLista* pl, void *pd, unsigned cantBytes);

int listaVacia(const tLista* pl, void *pd, unsigned cantBytes);
int listaLlena(const tLista* pl, void *pd, unsigned cantBytes);

int InsertarLuegodeN(tLista *pl, const void *pd, unsigned cantBytes,int n);
void Map(tLista *pl,void (*accion)(const void*));


#endif // TDALISTACIRCULAR_H_INCLUDED
