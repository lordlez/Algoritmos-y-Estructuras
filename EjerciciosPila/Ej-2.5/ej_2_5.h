#ifndef EJ_2_5_H
#define EJ_2_5_H
#include "../Ej-2.2/pila.h"
#include "../Ej-2.3/ej_2_3.h"

int cargar_archivo_bin_en_pilaE(const char *ruta, tPila *pp);
void mostrar_producto(tProducto *prod);
void menu(tPila *pp);
void opcion1(tPila *pp);
void opcion2(tPila *pp);
void opcion3(tPila *pp);
int cargar_de_pila_a_archivo(const char *ruta, tPila *pp);




#endif