#ifndef EJ_2_5_H
#define EJ_2_5_H


#include "../Ej-2.2/pilaDinamica.h"
#include "../Ej-2.3/ej-2_3.h"

int cargar_pila_con_archivo(tPila *pp, const char *ruta);
void menu(tPila *pp, const char *ruta);
void opcion1(tPila *pp);
void opcion2(tPila *pp);
void opcion3(tPila *pp);
int opcion4(tPila *pp, const char *ruta);



#endif // EJ_2_5_H