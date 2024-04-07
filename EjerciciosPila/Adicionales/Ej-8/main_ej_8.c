#include "ej_8.h"


int main(){

    int numero;
    tPila pilaMazo, pilaJugador1, pilaJugador2;

    crear_pila(&pilaMazo);
    crear_pila(&pilaJugador1);
    crear_pila(&pilaJugador2);

    cargar_pila(&pilaMazo);

    if(ver_tope(&pilaMazo, &numero, sizeof(int))){
        printf("El tope de mazo: %d\n", numero);
    }

    repartir_mazo(&pilaMazo, &pilaJugador1, &pilaJugador2);

    if(ver_tope(&pilaJugador1, &numero, sizeof(int))){
        printf("El tope de jugador1: %d\n", numero);
    }

    if(ver_tope(&pilaJugador2, &numero, sizeof(int))){
        printf("El tope de jugador2: %d\n", numero);
    }


    return 0;
}