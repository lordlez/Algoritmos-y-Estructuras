#include "ej_3.h"


int main(){

    tPila pila1, pilaDestino;
    int numero;

    crear_pila(&pila1);
    crear_pila(&pilaDestino);

    cargar_pila(&pila1);

    ver_tope(&pila1, &numero, sizeof(int));
    printf("Tope pila origen: %d\n", numero);

    de_pila_a_pila(&pila1, &pilaDestino);

    if(ver_tope(&pila1, &numero, sizeof(int))){
        printf("Tope origen desapilado: %d\n", numero);
    }

    if(ver_tope(&pilaDestino, &numero, sizeof(int))){
        printf("Tope destino: %d\n", numero);
    }



    return 0;
}