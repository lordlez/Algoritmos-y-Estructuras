#include "ej_5.h"
#include "../../Ej-2.2/pila.c"

void cargar_pila(tPila *pp){
    int i = 0, numero;
    while(!pila_llena(pp, sizeof(int)) && i < 3){
        printf("Ingrese un numero a la pila: ");
        scanf("%d", &numero);
        apilar(pp, &numero, sizeof(int));
        i++;
    }
}

void cargar_pila_a_vector(tPila *ppr, int *vecr, int *cer){
    int numero;
    while(!pila_vacia(ppr)){
        desapilar(ppr, &numero, sizeof(int));
        *vecr = numero;
        vecr++;
        (*cer)++;
        printf("Pase al vector el numero: %d\n", numero);
    }
}

void de_vector_a_pila(int *vec, int ce, tPila *pp){
    int i = 0, numero;
    while(!pila_llena(pp, sizeof(int)) && i < ce){
        numero = *vec;
        apilar(pp, &numero, sizeof(int));
        vec++;
        i++;
    }
}

