#include "ej_2_4.h"

int main(){

    tPila pila;
    char ruta[] = "../Ej-2.3/datos.dat";

    crear_pila(&pila);
    cargar_archivo_bin_en_pilaE(ruta, &pila);
    menu(&pila);
    cargar_de_pila_a_archivo(ruta, &pila);

    return 0;
}

