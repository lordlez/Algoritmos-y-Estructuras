#include "ej_3_6.h"

int main(){

    char ruta[] = "../../EjerciciosPila/Ej-2.3/datos.dat";
    char ruta2[] = "datos1.dat";
    char ruta3[] = "datos2.dat";
    tPila pila;

    crear_pila(&pila);

    generar_archivos(ruta, ruta2, ruta3, &pila);


    return 0;
}



