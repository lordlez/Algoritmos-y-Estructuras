#include "ej_1.h"

int main(){

    tPila pila1, pilaAux1, pilaAux2;
    int numero;

    crear_pila(&pila1);
    crear_pila(&pilaAux1);
    crear_pila(&pilaAux2);
    cargar_pila(&pila1);

    ver_tope(&pila1, &numero, sizeof(int));
    printf("Tope pila1: %d\n", numero);
    
    de_pila_a_pilas(&pila1, &pilaAux1, &pilaAux2);


    ver_tope(&pilaAux1, &numero, sizeof(int));
    printf("Tope pilaAux1: %d\n", numero);

    ver_tope(&pilaAux2, &numero, sizeof(int));
    printf("Tope pilaAux2: %d\n", numero);


    return 0;
}