#include "ej_7.h"
#include "../../Ej-2.2/pila.c"


void cargar_pila(tPila *pp){
    int numero, i = 0;
    while(!pila_llena(pp, sizeof(int)) && i<4){
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        apilar(pp, &numero, sizeof(int));
        i++;
    }
}

void ultimo_a_primero_de_pila(tPila *pp, int *vec){
    int numero, aux;
    int *pri = vec;
    while(!pila_vacia(pp)){
        desapilar(pp, &numero, sizeof(int));
        *vec = numero;
        vec++;
        printf("Puse en el vector: %d\n", numero);
    }
    vec--;
    aux = *vec;
    printf("Puse en aux: %d\n", aux);
    vec--;
    while(pri <= vec){
        if(!pila_llena(pp, sizeof(int))){
            numero = *vec;
            apilar(pp, &numero, sizeof(int));
            vec--;
            printf("Puse en la pila: %d\n", numero);
        }
    }
    if(!pila_llena(pp, sizeof(int))){
        apilar(pp, &aux, sizeof(int));
        printf("Puse en la pila: %d\n", aux);
    }
}