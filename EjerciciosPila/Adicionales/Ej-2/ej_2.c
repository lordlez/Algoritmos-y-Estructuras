#include "ej_2.h"
#include "../../Ej-2.2/pila.c"

void cargar_pila(tPila *pp){
    int numero, limite = 5, i = 0;
    while(!pila_llena(pp, 0) && i < limite){
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        apilar(pp, &numero, sizeof(int));
        i++;
    }
}

void de_pila_a_pila(tPila *pp1, tPila *pp2){
    int numero;
    while(!pila_vacia(pp1)){
        if(!pila_llena(pp2, 0)){
            desapilar(pp1, &numero, sizeof(int));
            apilar(pp2, &numero, sizeof(int));
        }
    }
}


