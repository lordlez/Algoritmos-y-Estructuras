#ifndef EJ_2_7_H
#define EJ_2_7_H

#include "../Ej-2.2/pila.h"

void cargar_pila(tPila *pp, int *vec, int longitud);
void sumar_pilas(tPila *pp1, tPila *pp2, tPila *ppr);
void cargar_pila_a_vector(tPila *ppr, int *vecr, int *cer);
void mostrar_vector(int *vecr, int cer);


#endif