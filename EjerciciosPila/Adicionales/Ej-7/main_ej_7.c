#include "ej_7.h"

int main(){

    int vec[] = {};
    int numero;
    tPila pila1;


    crear_pila(&pila1);
    cargar_pila(&pila1);

    if(ver_tope(&pila1, &numero, sizeof(int))){
        printf("Tope pila1: %d\n", numero);
    }

    ultimo_a_primero_de_pila(&pila1, vec);

    if(ver_tope(&pila1, &numero, sizeof(int))){
        printf("Tope pila1: %d\n", numero);
    }

    return 0;
}