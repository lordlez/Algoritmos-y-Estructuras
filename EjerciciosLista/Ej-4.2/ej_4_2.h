#ifndef EJ_4_2_H
#define EJ_4_2_H

#include "../Ej-4.1/lista.h"
#include "../../EjerciciosPila/Ej-2.3/ej_2_3.h"

int ordenar_archivo_v1(const char *ruta, tLista *pl);
int ordenar_archivo_v2(const char *ruta, tLista *pl);
int cmp_productos(const void *e1, const void *e2);
int mostrar_archivo(const char *ruta);
void mostrar(tProducto *prod);

#endif // EJ_4_2_H