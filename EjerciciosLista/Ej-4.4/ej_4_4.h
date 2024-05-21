#ifndef EJ_4_4_H
#define EJ_4_4_H

#include "../../EjerciciosLista/Ej-4.1/lista.h"


int buscar_cla(tLista *pl, void *pd, unsigned tam, int (*cmp)(const void *, const void *));
int cmp_enteros(const void *a, const void *b);
int buscar_cla_y_eliminar(tLista *pl, void *pd, unsigned tam, int (*cmp)(const void *, const void *));
void mostrar_entero(void *a);
int contar_cla(tLista *pl, void *pd, unsigned tam, int (*cmp)(const void *, const void *));


#endif // EJ_4_4_H