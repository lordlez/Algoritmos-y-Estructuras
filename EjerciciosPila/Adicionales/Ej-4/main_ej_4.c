#include "ej_4.h"


int main(){

    tPila pilaOrigen, pilaDestino, pilaAux;
    int numero;

    crear_pila(&pilaOrigen);
    crear_pila(&pilaDestino);
    crear_pila(&pilaAux);

    cargar_pila(&pilaOrigen);

    if(ver_tope(&pilaOrigen, &numero, sizeof(int))){
        printf("Tope Origen: %d\n", numero);
    }

    de_origen_a_destino(&pilaOrigen, &pilaAux);

    if(ver_tope(&pilaAux, &numero, sizeof(int))){
        printf("Tope Aux: %d\n", numero);
    }

    de_origen_a_destino(&pilaAux, &pilaDestino);

    if(ver_tope(&pilaDestino, &numero, sizeof(int))){
        printf("Tope Destino: %d\n", numero);
    }

    return 0;
}