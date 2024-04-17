#include "ej_11.h"

int main(){

    tPila pilaModelo, pila1, pilaAux;
    int numero;

    crear_pila(&pilaModelo);
    crear_pila(&pila1);
    crear_pila(&pilaAux);


    printf("Para la pila Modelo:\n");
    cargar_pila(&pilaModelo);
    printf("Para la pila 1:\n");
    cargar_pila(&pila1);

    if(!pila_vacia(&pila1)){
        ver_tope(&pila1, &numero, sizeof(int));
        printf("Tope pila1: %d\n", numero);
    }

    if(!pila_vacia(&pilaModelo)){
        ver_tope(&pilaModelo, &numero, sizeof(int));
        printf("Tope pilaModelo: %d\n", numero);
    }

    eliminar_iguales(&pila1, &pilaModelo, &pilaAux);

    if(!pila_vacia(&pila1)){
        ver_tope(&pila1, &numero, sizeof(int));
        printf("Tope pila1: %d\n", numero);
    }


    return 0;
}