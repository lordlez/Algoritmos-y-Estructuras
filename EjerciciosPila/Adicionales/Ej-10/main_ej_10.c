#include "ej_10.h"

int main(){

    tPila pilaA, pilaB;
    tElemento elementoA[100];
    tElemento elementoB[100];

    crear_pila(&pilaA);
    crear_pila(&pilaB);

    printf("Para la pilaA\n");
    cargar_pila(&pilaA, elementoA);
    printf("Para la pilaB\n");
    cargar_pila(&pilaB, elementoB);

    if(ver_tope(&pilaA, &elementoA, sizeof(tElemento))){
        printf("Tope pilaA: %d\n", elementoA->numero);
    }

    if(ver_tope(&pilaB, &elementoB, sizeof(tElemento))){
        printf("Tope pilaB: %d\n", elementoA->numero);
    }

    comparar_dos_pilas(&pilaA, &pilaB);





    return 0;
}