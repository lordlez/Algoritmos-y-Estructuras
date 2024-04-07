#include "ej_8.h"
#include "../../Ej-2.2/pila.c"

void cargar_pila(tPila *pp){
    int i = 0, numero;
    while(!pila_llena(pp, sizeof(int)) && i<5){
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        apilar(pp, &numero, sizeof(int));
        i++;
    }
}

void repartir_mazo(tPila *mazo, tPila *jugador1, tPila *jugador2){
    int numero;
    while(!pila_vacia(mazo)){
        desapilar(mazo, &numero, sizeof(int));
        if(!pila_llena(jugador1, sizeof(int))){
            apilar(jugador1, &numero, sizeof(int));
        }
        if(!pila_vacia(mazo)){
            if(!pila_llena(jugador2, sizeof(int))){
                desapilar(mazo, &numero, sizeof(int));
                apilar(jugador2, &numero, sizeof(int));
            }
        }
    }
}
