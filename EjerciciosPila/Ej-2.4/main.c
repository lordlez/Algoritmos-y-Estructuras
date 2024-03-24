#include "header.h"

int main(){

    tPila pila;
    int opcion;
    char ruta[] = "../Ej-2.3/datos.dat";

    archivo_a_pila(ruta, &pila);

    menu(&pila);

    comprobar_pila(ruta, &pila);

    leer_archivo(ruta);

    return 0;
}
