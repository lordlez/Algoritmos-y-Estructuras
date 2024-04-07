#include "ej_9.h"


int main(){

    tPila pilaA, pilaB;

    crear_pila(&pilaA);
    crear_pila(&pilaB);

    printf("Para la pilaA\n");
    cargar_pila(&pilaA);
    printf("Para la pilaB\n");
    cargar_pila(&pilaB);

    comparar_pilas(&pilaA, &pilaB);


    return 0;
}