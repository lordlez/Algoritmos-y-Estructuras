#ifndef EJ_2_7_MEJORADO_H
#define EJ_2_7_MEJORADO_H

//#include "../Ej-2.1/pila.h" //Pila estatica
#include "../Ej-2.2/pila.h" //Pila dinamica

void cargar_pila(tPila *pp, char *vec, int longitud);
void sumar_pilas(tPila *pp1, tPila *pp2, tPila *ppr);
void cargar_pila_a_vector(tPila *ppr, char *vecr, int *cer);
void mostrar_vector(char *vecr, int cer);

#endif