#include "ej-2_5.h"

int main(){

    tPila pila;
    char ruta[] = "../Ej-2.3/datos.dat";

    crear_pila(&pila);
    cargar_pila_con_archivo(&pila, ruta);
    menu(&pila, ruta);

    return 0;
}