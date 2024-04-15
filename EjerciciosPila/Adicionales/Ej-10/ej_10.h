#ifndef EJ_10_H
#define EJ_10_H

#include "../../Ej-2.2/pila.h"

typedef struct{
    int numero;
    int pos;
}tElemento;

void cargar_pila(tPila *pp, tElemento *el);
void comparar_dos_pilas(tPila *pilaA, tPila *pilaB);


#endif