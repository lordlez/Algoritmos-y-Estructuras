#include "pilaDinamica.h"

int main(){

    tPila pila;
    int numero1 = 1, numero2 = 2, numero3 = 3, resultado;

    crear_pila(&pila);

    if(!pila_llena(&pila, sizeof(int))){
        apilar(&pila, &numero1, sizeof(int));
    }

    if(!pila_vacia(&pila)){
        ver_tope(&pila, &resultado, sizeof(int));
        printf("Tope: %d\n", resultado);
    }

    if(!pila_llena(&pila, sizeof(int))){
        apilar(&pila, &numero2, sizeof(int));
    }

    if(!pila_vacia(&pila)){
        ver_tope(&pila, &resultado, sizeof(int));
        printf("Tope: %d\n", resultado);
    }

    if(!pila_vacia(&pila)){
        desapilar(&pila, &resultado, sizeof(int));
    }

    if(!pila_vacia(&pila)){
        ver_tope(&pila, &resultado, sizeof(int));
        printf("Tope: %d\n", resultado);
    }

    vaciar_pila(&pila);

    if(!pila_vacia(&pila)){
        ver_tope(&pila, &resultado, sizeof(int));
    }else{
        printf("La pila fue vaciada");
    }

    return 0;

}
