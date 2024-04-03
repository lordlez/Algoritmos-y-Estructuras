#include "ej_2.h"


int main(){

    tPila pilaOrigen, pilaDestino;
    int numero;

    crear_pila(&pilaOrigen);
    crear_pila(&pilaDestino);

    cargar_pila(&pilaOrigen);

    ver_tope(&pilaOrigen, &numero, sizeof(int));
    printf("Tope pilaOrigen: %d\n", numero);

    de_pila_a_pila(&pilaOrigen, &pilaDestino);

    if(ver_tope(&pilaOrigen, &numero, sizeof(int))){
        printf("Tope pilaOrigen: %d\n", numero);
    }else{
        printf("PilaOrigen vacia\n");
    }

    ver_tope(&pilaDestino, &numero, sizeof(int));
    printf("Tope pilaOrigen: %d\n", numero);



    return 0;
}