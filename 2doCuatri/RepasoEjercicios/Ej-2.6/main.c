#include "ej-2_6.h"


int main(){
    char ruta[] = "../Ej-2.3/datos.dat";
    tPila pila1;
    tPila pila2;

    crear_pila(&pila1);
    crear_pila(&pila2);
    ordenar_archivo_con_pilas(ruta, &pila1, &pila2);
    mostrar_archivo(ruta);


    return 0;
}