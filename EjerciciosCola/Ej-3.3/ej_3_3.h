#ifndef EJ_3_3_H
#define EJ_3_3_H

#include "../Ej-3.1/colaE.h"
#include "../../EjerciciosPila/Ej-2.3/ej_2_3.h"

int cargar_archivo_bin_en_colaE(const char *ruta, tCola *pc);
void mostrar_producto(tProducto *prod);
void menu(tCola *pc);
void opcion1(tCola *pc);
void opcion2(tCola *pc);
void opcion3(tCola *pc);
int cargar_de_cola_a_archivo(const char *ruta, tCola *pc);




#endif //EJ_3_3_H